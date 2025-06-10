#include <iostream>
using namespace std;

// Function to calculate the length of a char array (C-style string)
// Stops counting when it finds the null character '\0' or reaches max size
int getLength(char arr[], int size) {
    int count = 0;
    for(int index = 0; index < size; index++) {
        if(arr[index] == '\0') { // Null character marks end of string
            break;
        } else {
            count++; // Count characters until '\0'
        }
    }
    return count;
}

// Function to replace all occurrences of originalChar with newChar in the array
void replaceCharacter(char originalChar, char newChar, char arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == originalChar) {
            arr[i] = newChar; // Replace the character
        }
    }
}

// Convert all lowercase letters in the char array to uppercase
void convertIntoUpperCase(char arr[], int n) {
    int len = getLength(arr, n);
    for(int i = 0; i < len; i++) {
        char ch = arr[i];
        // Check if character is lowercase letter
        if(ch >= 'a' && ch <= 'z') {
            // Convert to uppercase by ASCII arithmetic
            ch = ch - 'a' + 'A';
        }
        arr[i] = ch; // Update the character in array
    }
}

// Convert all uppercase letters in the char array to lowercase
void convertIntoLowerCase(char arr[], int n) {
    int len = getLength(arr, n);
    for(int i = 0; i < len; i++) {
        char ch = arr[i];
        // Check if character is uppercase letter
        if(ch >= 'A' && ch <= 'Z') {
            // Convert to lowercase by ASCII arithmetic
            ch = ch - 'A' + 'a';
        }
        arr[i] = ch; // Update the character in array
    }
}

// Reverse the characters in the char array
void reverseCharArray(char arr[], int n) {
    int len = getLength(arr, n);
    int i = 0;
    int j = len - 1;

    // Swap characters from start and end moving towards center
    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// Check if the char array is a palindrome
bool checkPalindrome(char arr[], int n) {
    int len = getLength(arr, n);
    int i = 0;
    int j = len - 1;

    // Compare characters from start and end moving towards center
    while(i < j) {
        if(arr[i] != arr[j]) {
            return false; // Mismatch means not a palindrome
        }
        i++;
        j--;
    }
    return true; // All matched means palindrome
}

int main() {
    // Input two character arrays (strings)
    char arr1[100];
    cout << "Enter first string (no spaces): ";
    cin >> arr1;  // Input ends at whitespace

    char arr2[100];
    cout << "Enter second string (no spaces): ";
    cin >> arr2;

    // Show lengths of the inputs
    cout << "Length of first string: " << getLength(arr1, 100) << endl;
    cout << "Length of second string: " << getLength(arr2, 100) << endl;

    // Replace '@' with space ' ' in arr1 and display
    replaceCharacter('@', ' ', arr1, 100);
    cout << "After replacing '@' with ' ' in first string: " << arr1 << endl;

    // Convert arr1 to uppercase and print
    convertIntoUpperCase(arr1, 100);
    cout << "First string in uppercase: " << arr1 << endl;

    // Convert arr2 to lowercase and print
    convertIntoLowerCase(arr2, 100);
    cout << "Second string in lowercase: " << arr2 << endl;

    // Reverse arr1 and print
    reverseCharArray(arr1, 100);
    cout << "Reversed first string: " << arr1 << endl;

    // Check palindrome for arr2
    bool isPalindrome = checkPalindrome(arr2, 100);
    if(isPalindrome)
        cout << "Second string is a palindrome." << endl;
    else
        cout << "Second string is NOT a palindrome." << endl;

    return 0;
}
