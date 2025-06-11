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