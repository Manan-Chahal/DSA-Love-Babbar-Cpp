/*
LeetCode 1717. Maximum Score From Removing Substrings

Problem Statement:
------------------
You are given a string s and two integers x and y. You can perform two types of operations any number of times:
- Remove substring "ab" and gain x points.
- Remove substring "ba" and gain y points.

Return the maximum points you can gain after applying the above operations on s.

Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19

Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

Constraints:
1 <= s.length <= 10^5
1 <= x, y <= 10^4
s consists of lowercase English letters.

Approach:
---------
- Always remove the higher scoring pair first to maximize the total score.
- Use two passes with stacks (strings used as stacks):
    1. First pass: Remove all high-priority pairs ("ab" or "ba" depending on which score is higher).
    2. Second pass: Remove all low-priority pairs from the result of the first pass.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        int totalScore = 0;
        std::string highPriorityPair = (x > y) ? "ab" : "ba";
        std::string lowPriorityPair = (x > y) ? "ba" : "ab";
        int highPriorityScore = std::max(x, y);
        int lowPriorityScore = std::min(x, y);

        // First Pass: Remove the higher-scoring pair
        std::string stringAfterFirstPass;
        for (char c : s) {
            // Check if the current character forms a high-priority pair
            // with the last character of our temporary string.
            if (!stringAfterFirstPass.empty() && 
                stringAfterFirstPass.back() == highPriorityPair[0] && 
                c == highPriorityPair[1]) {
                
                stringAfterFirstPass.pop_back();
                totalScore += highPriorityScore;
            } else {
                stringAfterFirstPass.push_back(c);
            }
        }

        // Second Pass: Remove the lower-scoring pair from the result of the first pass
        std::string finalString;
        for (char c : stringAfterFirstPass) {
            // Check for the low-priority pair
            if (!finalString.empty() && 
                finalString.back() == lowPriorityPair[0] && 
                c == lowPriorityPair[1]) {
                
                finalString.pop_back();
                totalScore += lowPriorityScore;
            } else {
                finalString.push_back(c);
            }
        }

        return totalScore;
    }
};