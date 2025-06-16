    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <string>
    using namespace std;

    class Solution {
    public:
        // This function normalizes a string by replacing its characters
        // with sequential characters starting from 'a' based on first appearance.
        void normalise(string &str) {
            char start = 'a';  // Start character for normalization
            unordered_map<char, char> mapping; // To track character mapping

            // First pass: Build the mapping based on character order
            for (int i = 0; i < str.length(); i++) {
                char stringKaCharacter = str[i];
                if (mapping.find(stringKaCharacter) == mapping.end()) {
                    // If character is not yet mapped, assign the next available char
                    mapping[stringKaCharacter] = start;
                    start++;
                }
            }

            // Second pass: Replace original string characters with normalized ones
            for (int i = 0; i < str.length(); i++) {
                char mappedCharacter = mapping[str[i]];
                str[i] = mappedCharacter;
            }
            // The input string `str` is now normalized
        }

        // Main function to find words matching the normalized pattern
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            vector<string> ans;

            // Step A: Normalize the given pattern
            normalise(pattern);

            // Step B: Normalize each word and compare with pattern
            for (int i = 0; i < words.size(); i++) {
                string currWord = words[i];  // Copy current word
                string temp = currWord;      // Keep original for result

                normalise(currWord);         // Normalize the word
                if (currWord == pattern) {   // If normalized form matches pattern
                    ans.push_back(temp);     // Add original word to result
                }
            }

            return ans; // Return list of matching words
        }
    };

    int main() {
        Solution obj;

        vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
        string pattern = "abb";

        vector<string> result = obj.findAndReplacePattern(words, pattern);

        cout << "Words matching the pattern '" << pattern << "':\n";
        for (string word : result) {
            cout << word << " ";
        }
        cout << endl;

        return 0;
    }
