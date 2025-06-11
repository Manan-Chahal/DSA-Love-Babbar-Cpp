#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // This function expands around a center (i, j) and counts palindromic substrings
    int expandAroundCenter(string s, int i, int j) {
        int count = 0;

        // Expand as long as i and j are within bounds and characters match
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;    // Found a palindrome
            i--;        // Move left
            j++;        // Move right
        }

        // Return the count of palindromic substrings for this center
        return count;
    }

    // This function counts all palindromic substrings in the string s
    int countSubstrings(string s) {
        int totalCount = 0;  // To keep total count of palindromic substrings

        // Iterate through each character and consider it as the center
        for (int center = 0; center < s.length(); center++) {
            // Case 1: Odd length palindromes (e.g., "aba")
            // Center is at a single character
            int oddCount = expandAroundCenter(s, center, center);

            // Case 2: Even length palindromes (e.g., "abba")
            // Center is between two characters
            int evenCount = expandAroundCenter(s, center, center + 1);

            // Add both counts to total
            totalCount += oddCount + evenCount;
        }

        // Return the total number of palindromic substrings
        return totalCount;
    }
};

int main() {
    Solution obj;

    // Example test case
    string input = "aaa";

    // Count palindromic substrings
    int result = obj.countSubstrings(input);

    // Print the result
    cout << "Total palindromic substrings in \"" << input << "\": " << result << endl;

    return 0;
}
