#include <iostream>
using namespace std;

class Solution {
public:
    // Utility function to check if the substring s[start...end] is a palindrome
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Function to return the longest palindromic substring
    string longestPalindrome(string s) {
        string ans = "";

        // Check all substrings
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                // Check if the substring s[i...j] is a palindrome
                if (isPalindrome(s, i, j)) {
                    string t = s.substr(i, j - i + 1); // extract the substring
                    if (t.size() > ans.size()) {
                        ans = t; // update if it's the longest found so far
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string input = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input) << endl;
    return 0;
}
