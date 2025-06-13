#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//good 
class Solution
{
public:
    // Step 1: Create mapping from characters in the key to a-z
    void createMapping(unordered_map<char, char> &mapping, string key)
    {
        char start = 'a'; // Start mapping from 'a'

        for (int i = 0; i < key.length(); i++)
        {
            // Ignore if the character is already mapped or is a space
            if (key[i] != ' ' && mapping.find(key[i]) == mapping.end())
            {
                mapping[key[i]] = start; // Map this character to current letter
                start++;                 // Move to next letter
            }
        }
    }

    // Step 2: Decode the message using the mapping
    string useMapping(unordered_map<char, char> &mapping, string message)
    {
        string ans = "";

        for (int i = 0; i < message.length(); i++)
        {
            char mappedCharacter = mapping[message[i]]; // Get mapped character
            ans.push_back(mappedCharacter);             // Add to result
        }

        return ans;
    }

    // Main function that glues the above two together
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> mapping;

        // Always map space to space
        mapping[' '] = ' ';

        // Step 1: Create mapping from key
        createMapping(mapping, key);

        // Step 2: Decode the message using mapping
        string ans = useMapping(mapping, message);

        return ans;
    }
};

int main()
{
    Solution obj;

    // Example inputs
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    // Call decodeMessage
    string result = obj.decodeMessage(key, message);

    // Output the result
    cout << "Decoded Message: " << result << endl;

    return 0;
}