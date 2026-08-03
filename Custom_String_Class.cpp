
#include <iostream>
using namespace std;

class String {
    char *str;

    //  to find string length
    static int getLen(const char* s) {
        int i = 0;
        while (s && s[i] != '\0') i++;
        return i;
    }

public:
    

    // Default Constructor  
    String() {  
        str = new char[1];  
        str[0] = '\0';  
    }  

    // Parameterized Constructor  
    String(const char *s) {  
        if (!s) {
            str = new char[1];
            str[0] = '\0';
            return;
        }
        int len = getLen(s);  
        str = new char[len + 1];  
        for (int i = 0; i <= len; i++) {
            str[i] = s[i];  
        }
    }  

    // Copy Constructor (Deep Copy)
    String(const String &s) {  
        int len = getLen(s.str);  
        str = new char[len + 1];  
        for (int i = 0; i <= len; i++) {
            str[i] = s.str[i];  
        }
    }  

    // Destructor
    ~String() {  
        delete[] str;  
    }  

    /

    void setData() {  
        char tempArr[1024];
        cout << "Enter String : ";  
        cin.getline(tempArr, 1024);  

        delete[] str;
        int len = getLen(tempArr);
        str = new char[len + 1];
        for (int i = 0; i <= len; i++) {
            str[i] = tempArr[i];
        }
    }  

    void getData() const {  
        cout << str << endl;  
    }  

    // Assignment Operator (Deep Copy)
    String& operator=(const String &s) {  
        if (this == &s) return *this; // Self-assignment check

        delete[] str;  
        int len = getLen(s.str);  
        str = new char[len + 1];  
        for (int i = 0; i <= len; i++) {
            str[i] = s.str[i];  
        }
        return *this;  
    }  

    // + Operator  
    String operator+(const String &s) const {  
        int len1 = getLen(str);
        int len2 = getLen(s.str);

        char *tempBuf = new char[len1 + len2 + 1];

        int i = 0, j = 0;
        for (i = 0; i < len1; i++) tempBuf[i] = str[i];
        for (j = 0; j < len2; j++) tempBuf[i++] = s.str[j];
        tempBuf[i] = '\0';

        String res(tempBuf);
        delete[] tempBuf;
        return res;  
    }

    // Subscript Operator []
    char& operator[](int index) {
        return str[index];
    }

    const char& operator[](int index) const {
        return str[index];
    }

    // Equality Operators
    int operator==(const String &s) const {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0') {  
            if (str[i] != s.str[i]) return 0;  
            i++;  
        }  
        return str[i] == s.str[i];
    }

    int operator!=(const String &s) const {
        return !(*this == s);
    }

    // Relational Operators
    bool operator<(const String &s) const {
        int i = 0;
        while (str[i] != '\0' && s.str[i] != '\0') {
            if (str[i] != s.str[i]) return str[i] < s.str[i];
            i++;
        }
        return str[i] < s.str[i];
    }

    bool operator>(const String &s) const {
        return s < *this;
    }

    bool operator<=(const String &s) const {
        return !(*this > s);
    }

    bool operator>=(const String &s) const {
        return !(*this < s);
    }

    
    friend ostream& operator<<(ostream&, const String&);  
    friend istream& operator>>(istream&, String&);  

    friend void strcpy(String&, const String&);  
    friend void strncpy(String&, const String&, int);  
    friend int strcmp(const String&, const String&);  
    friend int strncmp(const String&, const String&, int);  
    friend void strcat(String&, const String&);  
    friend void strncat(String&, const String&, int);  
    friend void strrev(String&);  
    friend void strupr(String&);  
    friend void strlwr(String&);  
    friend int strchr(const String&, char);  
    friend int strrchr(const String&, char);  
    friend int strstr(const String&, const String&);  
    friend int strlen(const String&);
};



// string copy
void strcpy(String &s1, const String &s2) {
    delete[] s1.str;
    int len = String::getLen(s2.str);
    s1.str = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        s1.str[i] = s2.str[i];
    }
}

// string n copy
void strncpy(String &s1, const String &s2, int n) {
    delete[] s1.str;
    s1.str = new char[n + 1];
    int i;
    for (i = 0; i < n && s2.str[i] != '\0'; i++) {
        s1.str[i] = s2.str[i];
    }
    s1.str[i] = '\0';
}

// strcmp
int strcmp(const String &s1, const String &s2) {
    int i = 0;
    for (i = 0; s1.str[i] != '\0' && s2.str[i] != '\0'; i++) {  
        if (s1.str[i] != s2.str[i])  
            return s1.str[i] - s2.str[i];  
    }  
    return s1.str[i] - s2.str[i];
}

// strncmp
int strncmp(const String &s1, const String &s2, int n) {
    int i;
    for (i = 0; i < n && s1.str[i] != '\0' && s2.str[i] != '\0'; i++) {  
        if (s1.str[i] != s2.str[i])  
            return s1.str[i] - s2.str[i];  
    }  
    if (i == n) return 0;  
    return s1.str[i] - s2.str[i];
}

// strcat
void strcat(String &s1, const String &s2) {
    int len1 = String::getLen(s1.str);
    int len2 = String::getLen(s2.str);

    char *newStr = new char[len1 + len2 + 1];

    int i = 0, j = 0;
    for (i = 0; i < len1; i++) newStr[i] = s1.str[i];
    for (j = 0; j < len2; j++) newStr[i++] = s2.str[j];
    newStr[i] = '\0';

    delete[] s1.str;
    s1.str = newStr;
}

// strncat
void strncat(String &s1, const String &s2, int n) {
    int len1 = String::getLen(s1.str);
    int len2 = String::getLen(s2.str);
    int catLen = (n < len2) ? n : len2;

    char *newStr = new char[len1 + catLen + 1];

    int i = 0, j = 0;
    for (i = 0; i < len1; i++) newStr[i] = s1.str[i];
    for (j = 0; j < catLen; j++) newStr[i++] = s2.str[j];
    newStr[i] = '\0';

    delete[] s1.str;
    s1.str = newStr;
}

// strrev
void strrev(String &s) {
    int len = String::getLen(s.str);
    for (int i = 0; i < len / 2; i++) {  
        char temp = s.str[i];  
        s.str[i] = s.str[len - 1 - i];  
        s.str[len - 1 - i] = temp;  
    }
}

// strupr
void strupr(String &s) {
    for (int i = 0; s.str[i] != '\0'; i++) {  
        if (s.str[i] >= 'a' && s.str[i] <= 'z')  
            s.str[i] -= 32;  
    }
}

// strlwr
void strlwr(String &s) {
    for (int i = 0; s.str[i] != '\0'; i++) {  
        if (s.str[i] >= 'A' && s.str[i] <= 'Z')  
            s.str[i] += 32;  
    }
}

// strchr
int strchr(const String &s, char ch) {
    for (int i = 0; s.str[i] != '\0'; i++) {  
        if (s.str[i] == ch) return i;  
    }  
    return -1;
}

// strrchr
int strrchr(const String &s, char ch) {
    int lastIdx = -1;
    for (int i = 0; s.str[i] != '\0'; i++) {  
        if (s.str[i] == ch) lastIdx = i;  
    }  
    return lastIdx;
}

// strstr
int strstr(const String &s1, const String &s2) {
    for (int i = 0; s1.str[i] != '\0'; i++) {  
        int j = 0;
        for (; s2.str[j] != '\0'; j++) {  
            if (s1.str[i + j] != s2.str[j]) break;  
        }  
        if (s2.str[j] == '\0') return 1;  
    }  
    return 0;
}

// strlen
int strlen(const String &s) {
    return String::getLen(s.str);
}

// Stream Output Operator <<
ostream& operator<<(ostream &out, const String &s) {
    out << s.str;
    return out;
}

// Stream Input Operator >>
istream& operator>>(istream &in, String &s) {
    char tempArr[1024];
    in >> tempArr;
    s = String(tempArr);
    return in;
}



int main() {
    String s1, s2;
    int ch, n, pos, index;
    char c;

    while (1) {  
         
        cout<<"\n******String Class Implementation*******";
        cout << "\n----------------------------------------;
        cout << "\n1.strcpy       2.strncpy";
        cout << "\n3.strcmp       4.strncmp";  
        cout << "\n5.strcat       6.strncat";
        cout << "\n7.strrev       8.strupr";  
        cout << "\n9.strlwr       10.strchr";
        cout << "\n11.strrchr     12.strstr";  
        cout << "\n13.strlen      14.Subscript[]";
        cout << "\n15.Relational  16.Exit";  
        cout << "\n-----------------------------------------";

        cout << "\nEnter Choice : ";  
        cin >> ch;  
        cin.ignore();  

        switch (ch) {  
            case 1:  
                s1.setData();  
                s2.setData();  
                strcpy(s1, s2);  
                cout << "Result s1: " << s1 << endl;  
                break;  

            case 2:  
                s1.setData();  
                s2.setData();  
                cout << "Enter n : ";  
                cin >> n;  
                strncpy(s1, s2, n);  
                cout << "Result s1: " << s1 << endl;  
                break;  

            case 3:  
                s1.setData();  
                s2.setData();  
                if (strcmp(s1, s2) == 0)  
                    cout << "Equal" << endl;  
                else  
                    cout << "Not Equal" << endl;  
                break;  

            case 4:  
                s1.setData();  
                s2.setData();  
                cout << "Enter n : ";  
                cin >> n;  
                if (strncmp(s1, s2, n) == 0)  
                    cout << "Equal" << endl;  
                else  
                    cout << "Not Equal" << endl;  
                break;  

            case 5:  
                s1.setData();  
                s2.setData();  
                strcat(s1, s2);  
                cout << "Result s1: " << s1 << endl;  
                break;  

            case 6:  
                s1.setData();  
                s2.setData();  
                cout << "Enter n : ";  
                cin >> n;  
                strncat(s1, s2, n);  
                cout << "Result s1: " << s1 << endl;  
                break;  

            case 7:  
                s1.setData();  
                strrev(s1);  
                cout << "Reversed: " << s1 << endl;  
                break;  

            case 8:  
                s1.setData();  
                strupr(s1);  
                cout << "Uppercase: " << s1 << endl;  
                break;  

            case 9:  
                s1.setData();  
                strlwr(s1);  
                cout << "Lowercase: " << s1 << endl;  
                break;  

            case 10:  
                s1.setData();  
                cout << "Enter Character : ";  
                cin >> c;  
                pos = strchr(s1, c);
                if (pos != -1)  
                    cout << "Found at index " << pos << endl;  
                else  
                    cout << "Not Found" << endl;  
                break;  

            case 11:  
                s1.setData();  
                cout << "Enter Character : ";  
                cin >> c;  
                pos = strrchr(s1, c);
                if (pos != -1)  
                    cout << "Last present at index " << pos << endl;  
                else  
                    cout << "Not present" << endl;  
                break;  

            case 12:  
                s1.setData();  
                s2.setData();  
                if (strstr(s1, s2))  
                    cout << "Substring Found" << endl;  
                else  
                    cout << "Substring Not Found" << endl;  
                break;  

            case 13:  
                s1.setData();  
                cout << "Length = " << strlen(s1) << endl;  
                break;  

            case 14:  // Subscript Operator []
                s1.setData();
                cout << "Enter index to access: ";
                cin >> index;
                if (index >= 0 && index < strlen(s1)) {
                    cout << "Character at s1[" << index << "] = " << s1[index] << endl;
                } else {
                    cout << "Index out of bounds!" << endl;
                }
                break;

            case 15:  // Relational Operators (<, >, <=, >=, ==, !=)
                s1.setData();
                s2.setData();
                cout << "s1 == s2 : " << (s1 == s2 ? "True" : "False") << endl;
                cout << "s1 != s2 : " << (s1 != s2 ? "True" : "False") << endl;
                cout << "s1 < s2  : " << (s1 < s2  ? "True" : "False") << endl;
                cout << "s1 > s2  : " << (s1 > s2  ? "True" : "False") << endl;
                cout << "s1 <= s2 : " << (s1 <= s2 ? "True" : "False") << endl;
                cout << "s1 >= s2 : " << (s1 >= s2 ? "True" : "False") << endl;
                break;

            case 16:  
                return 0;  

            default:  
                cout << "Invalid Choice" << endl;  
        }  
    }  
}
