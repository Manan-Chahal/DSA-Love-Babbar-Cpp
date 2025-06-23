#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans; // Stores the final justified lines
        vector<string> currentLine; // Stores words for the current line
        int currentLineTotalChars = 0; // Total characters in current line (excluding spaces)

        for (int i = 0; i < words.size(); i++)
        {
            string &currentWord = words[i];
            int currentLineNeededNumberOfSpaces = currentLine.size(); // Number of spaces needed (one after each word except last)

            // Check if adding the current word would exceed maxWidth
            if (currentLineTotalChars + currentLineNeededNumberOfSpaces + currentWord.size() > maxWidth)
            {
                // If yes, process the current line for full justification

                int extraSpaces = maxWidth - currentLineTotalChars; // Total spaces to distribute
                // If only one word, avoid division by zero
                int spacesGoInBetweenWords = extraSpaces / max(1, (int)(currentLine.size() - 1)); // Minimum spaces between words
                int remainder = extraSpaces % max(1, (int)(currentLine.size() - 1)); // Extra spaces to distribute from left

                // Add spaces after each word except the last
                for (int j = 0; j < currentLine.size() - 1; j++)
                {
                    // Add even spaces
                    for (int k = 0; k < spacesGoInBetweenWords; k++)
                        currentLine[j] += " "; // Add spaces after the word

                    // Distribute the remainder (leftmost first)
                    if (remainder > 0)
                    {
                        currentLine[j] += " ";
                        remainder--;
                    }
                }

                if (currentLine.size() == 1)
                {
                    // If only one word, left justify by adding all spaces at the end
                    while (extraSpaces--)
                        currentLine[0] += " ";
                }

                // Concatenate all words in currentLine to form the final justified line
                string finalLine = "";
                for (string wordWithSpaces : currentLine)
                    finalLine += wordWithSpaces; // String concatenation

                ans.push_back(finalLine); // Add the justified line to the answer
                currentLine.clear(); // Clear for the next line
                currentLineTotalChars = 0; // Reset character count
            }

            // Add the current word to the current line
            currentLine.push_back(currentWord);
            currentLineTotalChars += currentWord.size(); // Update character count (spaces not included)
        }

        // Handle the last line (left-justified)
        string finalLine = "";
        for (auto word : currentLine)
            finalLine += word + " "; // Add a single space after each word

        finalLine.pop_back(); // Remove the extra space at the end

        // If the line is still shorter than maxWidth, pad spaces at the end
        int leftSpaces = maxWidth - finalLine.size();
        while (leftSpaces--)
            finalLine += " ";
        ans.push_back(finalLine); // Add the last line

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> result = sol.fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for (const string &line : result)
    {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}