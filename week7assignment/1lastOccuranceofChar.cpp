#include <iostream>
#include <string>
using namespace std;

// ✅ Left to Right recursive approach
int lastOccurrenceLTR(string s, char target, int i = 0) {
    // Base case: reached end of string
    if (i == s.length()) return -1;

    // Recursive call: check in the rest of the string
    int indexInRest = lastOccurrenceLTR(s, target, i + 1);

    // If found in rest, return that index
    if (indexInRest != -1) return indexInRest;

    // Otherwise, check current character
    if (s[i] == target) return i;

    // Not found
    return -1;
}

// ✅ Right to Left recursive approach
int lastOccurrenceRTL(string s, char target, int i) {
    // Base case: reached beginning
    if (i < 0) return -1;

    // If current char matches, return index
    if (s[i] == target) return i;

    // Recursive call to check earlier part
    return lastOccurrenceRTL(s, target, i - 1);
}

// ✅ Driver Code
int main() {
    string str;
    char target;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter the character to search for: ";
    cin >> target;

    int ltrIndex = lastOccurrenceLTR(str, target);
    int rtlIndex = lastOccurrenceRTL(str, target, str.length() - 1);

    cout << "\nLast Occurrence (Left to Right Recursion): " << ltrIndex << endl;
    cout << "Last Occurrence (Right to Left Recursion): " << rtlIndex << endl;

    return 0;
}
