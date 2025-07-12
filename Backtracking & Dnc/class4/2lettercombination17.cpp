/*
Leetcode 17: Letter Combinations of a Phone Number

Problem Statement:
------------------
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

Each digit maps to a set of letters as on a telephone keypad:
2 -> "abc", 3 -> "def", 4 -> "ghi", 5 -> "jkl", 6 -> "mno", 7 -> "pqrs", 8 -> "tuv", 9 -> "wxyz"

Approach (Backtracking):
------------------------
- For each digit, try every possible letter mapped to it.
- Use recursion to build all possible combinations.
- Backtrack after each recursive call to explore other possibilities.

Time Complexity:
----------------
- O(4^n), where n is the length of digits (since each digit can map to up to 4 letters).

Space Complexity:
-----------------
- O(n) recursion stack + O(4^n) for storing all combinations.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Recursive helper function to build combinations
    void solve(string &output, unordered_map<char,string> &mapping, vector<string> &ans, string digits, int i) {
        // Base case: if we've processed all digits
        if(i >= digits.length()) {
            if(output.length() > 0) {
                ans.push_back(output); // Add current combination to answer
            }
            return;
        }
        // Get the current digit and its mapped letters
        char digit = digits[i];
        string mappedString = mapping[digit];

        // Try every letter for the current digit
        for(char ch: mappedString) {
            output.push_back(ch); // Choose the letter
            solve(output, mapping, ans, digits, i+1); // Recurse for next digit
            output.pop_back(); // Backtrack: remove the letter
        }
    } 

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans; // Edge case: empty input

        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        int i = 0;
        string output = "";

        solve(output, mapping, ans, digits, i);

        return ans;
    }
};

// Test cases
int main() {
    Solution sol;

    vector<string> res1 = sol.letterCombinations("23");
    cout << "Test Case 1 (digits = \"23\"):" << endl;
    for(const string& s : res1) cout << s << " ";
    cout << endl;

    vector<string> res2 = sol.letterCombinations("");
    cout << "Test Case 2 (digits = \"\"):" << endl;
    for(const string& s : res2) cout << s << " ";
    cout << endl;

    vector<string> res3 = sol.letterCombinations("7");
    cout << "Test Case 3 (digits = \"7\"):" << endl;
    for(const string& s : res3) cout << s << " ";
    cout << endl;

    vector<string> res4 = sol.letterCombinations("234");
    cout << "Test Case 4 (digits = \"234\"):" << endl;
    for(const string& s : res4) cout << s << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- solve: Recursively builds all possible combinations by trying every letter for each digit.
- letterCombinations: Initializes mapping and starts recursion.
- main: Runs several test cases and prints all combinations.

Time Complexity: O(4^n)
Space Complexity: O(n) recursion + O(4^n) output
*/