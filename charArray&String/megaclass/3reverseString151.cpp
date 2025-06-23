#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end()); // e.g., "the sky is blue" => "eulb si yks eht"

        int n = s.size();       // size of string
        int start = 0, end = 0; // pointers for where to write words

        // Step 2 to 5: process the reversed string word by word
        for (int i = 0; i < n; i++) {

            // Step 2: Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i == n) break; // reached the end

            // Step 3: Copy characters from i to end (a word)
            while (i < n && s[i] != ' ')
                s[end++] = s[i++]; // copying word to the front of the string

            // Step 4: Reverse the individual word to correct orientation
            reverse(s.begin() + start, s.begin() + end);

            // Step 5: Add a space after the word
            s[end++] = ' ';

            // Update start for the next word
            start = end;
        }

        // Step 6: Resize the string to remove the trailing space
        // Explanation:
        // After processing, 'end' points just after the last character (which is a space).
        // s.resize(end - 1) removes this trailing space, so the result doesn't end with an extra space.
        // If no valid word was found, s.resize(0) makes the string empty.
        if (end > 0)
            s.resize(end - 1); // remove the last space
        else
            s.resize(0); // if no valid word found

        return s;
    }
};

int main() {
    Solution sol;
    string input;

    // Sample Input 1
    input = "the sky is blue";
    cout << "\nInput: \"" << input << "\"";
    cout << "\nExpected Output: \"blue is sky the\"";
    cout << "\nActual Output:   \"" << sol.reverseWords(input) << "\"";

    // Sample Input 2
    input = "  hello world  ";
    cout << "\n\nInput: \"" << input << "\"";
    cout << "\nExpected Output: \"world hello\"";
    cout << "\nActual Output:   \"" << sol.reverseWords(input) << "\"";

    // Sample Input 3
    input = "a good   example";
    cout << "\n\nInput: \"" << input << "\"";
    cout << "\nExpected Output: \"example good a\"";
    cout << "\nActual Output:   \"" << sol.reverseWords(input) << "\"";

    // Custom Case: Only spaces
    input = "    ";
    cout << "\n\nInput: \"" << input << "\"";
    cout << "\nExpected Output: \"\" (empty string)";
    cout << "\nActual Output:   \"" << sol.reverseWords(input) << "\"";

    // Custom Case: One word with spaces
    input = "   hello    ";
    cout << "\n\nInput: \"" << input << "\"";
    cout << "\nExpected Output: \"hello\"";
    cout << "\nActual Output:   \"" << sol.reverseWords(input) << "\"";

    return 0;
}
