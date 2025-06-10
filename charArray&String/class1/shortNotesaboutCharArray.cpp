#include <iostream>
#include <cctype>    // For toupper and tolower
using namespace std;

// 1. Demonstrate declaration and printing of char arrays
void demoCharArrayDeclaration() {
    char greeting[7] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char hello[] = "Hello";  // compiler adds '\0'

    cout << "Greeting: " << greeting << endl;
    cout << "Hello: " << hello << endl;
}

// 2. Show effect of missing null terminator
void demoMissingNullTerminator() {
    char withoutNull[5] = {'H', 'e', 'l', 'l', 'o'};  // No '\0'

    cout << "Without null terminator (may give garbage): " << withoutNull << endl;
}

// 3. Read input using cin and getline
void demoInputReading(char name[]) {
    cout << "Enter your name (no spaces): ";
    cin >> name;

    cout << "You entered (cin): " << name << endl;

    cin.ignore(); // clear leftover newline

    cout << "Enter your full name (with spaces): ";
    cin.getline(name, 50);

    cout << "You entered (getline): " << name << endl;
}

// 4. Calculate length of char array manually
int calculateLength(char str[]) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    cout << "Length of string: " << length << endl;
    return length;
}

// 5. Capitalize the first character
void capitalizeFirst(char str[]) {
    if(str[0] != '\0') {
        str[0] = toupper(str[0]);
    }
    cout << "After capitalizing first letter: " << str << endl;
}

// 6. Replace all spaces with underscores
void replaceSpaces(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            str[i] = '_';
        }
    }
    cout << "After replacing spaces with underscores: " << str << endl;
}

// 7. Manually copy one char array to another
void copyCharArray(char source[], char destination[]) {
    int i = 0;
    while(source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // don't forget null terminator
    cout << "Copied string: " << destination << endl;
}

// 8. Manually compare two char arrays
void compareCharArrays(char str1[], char str2[]) {
    bool equal = true;
    int i = 0;
    while(true) {
        if(str1[i] != str2[i]) {
            equal = false;
            break;
        }
        if(str1[i] == '\0') break;
        i++;
    }

    if(equal)
        cout << "\"" << str1 << "\" and \"" << str2 << "\" are equal" << endl;
    else
        cout << "\"" << str1 << "\" and \"" << str2 << "\" are NOT equal" << endl;
}

// 9. Reverse a char array
void reverseCharArray(char str[]) {
    int len = 0;
    while(str[len] != '\0') len++;

    int i = 0, j = len - 1;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    cout << "Reversed string: " << str << endl;
}

// 10. Convert string to uppercase
void convertToUpper(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    cout << "Uppercase string: " << str << endl;
}

// 11. Convert string to lowercase
void convertToLower(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    cout << "Lowercase string: " << str << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    demoCharArrayDeclaration();
    cout << "----------------------------------------" << endl;

    demoMissingNullTerminator();
    cout << "----------------------------------------" << endl;

    char name[50];
    demoInputReading(name);
    cout << "----------------------------------------" << endl;

    int len = calculateLength(name);
    cout << "----------------------------------------" << endl;

    capitalizeFirst(name);
    cout << "----------------------------------------" << endl;

    replaceSpaces(name);
    cout << "----------------------------------------" << endl;

    char copy[50];
    copyCharArray(name, copy);
    cout << "----------------------------------------" << endl;

    char str1[] = "apple";
    char str2[] = "apple";
    compareCharArrays(str1, str2);
    cout << "----------------------------------------" << endl;

    char toReverse[] = "hello";
    reverseCharArray(toReverse);
    cout << "----------------------------------------" << endl;

    char upperLower[] = "HeLLo WoRLd!";
    convertToUpper(upperLower);
    convertToLower(upperLower);
    cout << "----------------------------------------" << endl;

    return 0;
}
