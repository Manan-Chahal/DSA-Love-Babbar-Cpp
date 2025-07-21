#include <string>
#include <vector>

class Solution {
public:
    std::string makeFancyString(std::string s) {
        // ans will store the resulting fancy string.
        std::string ans = "";

        // Iterate through each character of the input string.
        for (char c : s) {
            int n = ans.length();
            
            // A character can be added if the result string has fewer than 2 characters,
            // or if the new character is not the same as the last two characters.
            if (n < 2 || ans[n - 1] != c || ans[n - 2] != c) {
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};