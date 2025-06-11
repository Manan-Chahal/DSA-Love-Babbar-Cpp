/*
LeetCode 1047. Remove All Adjacent Duplicates In String

Problem Statement:
You are given a string `s` consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Examples:

Input: s = "abbaca"
Output: "ca"
Explanation: 
- Remove "bb" → "aaca"
- Then remove "aa" → "ca"

Input: s = "azxxzy"
Output: "ay"

Constraints:
- 1 <= s.length <= 10^5
- s consists of lowercase English letters only.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // Initialize the answer string as empty
        string ans = "";
        int n = s.length();

        // Loop through each character in input string
        for (int i = 0; i < n; i++) {
            char currCharacter = s[i];

            // If ans is empty or current char is not equal to last char in ans, push it
            if (ans.empty() || currCharacter != ans.back()) {
                ans.push_back(currCharacter);  // Add current char to ans
            }
            // If current char equals the last char in ans, remove the last char
            else {
                ans.pop_back();  // Remove the duplicate
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string input1 = "abbaca";
    cout << "Input: " << input1 << endl;
    cout << "Output: " << sol.removeDuplicates(input1) << endl;  // Output: "ca"

    string input2 = "azxxzy";
    cout << "Input: " << input2 << endl;
    cout << "Output: " << sol.removeDuplicates(input2) << endl;  // Output: "ay"

    string input3 = "aabbccdd";
    cout << "Input: " << input3 << endl;
    cout << "Output: " << sol.removeDuplicates(input3) << endl;  // Output: ""

    return 0;
}
