#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if substring s[e..e] is a palindrome
    bool checkPalindrome(string str, int s, int e) {
        while (s <= e) {
            if (str[s] != str[e]) {
                return false;  // Mismatch found
            }
            s++;
            e--;
        }
        return true;  // No mismatch, it is a palindrome
    }

    // Main function to check if string is valid palindrome with at most one deletion
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                // If characters match, move inward
                i++;
                j--;
            } else {
                // Mismatch found, try deleting one character either from start or end
                bool skipLeft = checkPalindrome(s, i + 1, j);  // Skip s[i]
                bool skipRight = checkPalindrome(s, i, j - 1); // Skip s[j]
                return skipLeft || skipRight;  // Valid if either path leads to a palindrome
            }
        }

        return true;  // Original string was a palindrome
    }
};

int main() {
    Solution obj;

    // Example test cases
    string input1 = "abca";
    string input2 = "racecar";
    string input3 = "abc";

    cout << "Input: " << input1 << " → Output: " << (obj.validPalindrome(input1) ? "true" : "false") << endl;
    cout << "Input: " << input2 << " → Output: " << (obj.validPalindrome(input2) ? "true" : "false") << endl;
    cout << "Input: " << input3 << " → Output: " << (obj.validPalindrome(input3) ? "true" : "false") << endl;

    return 0;
}
