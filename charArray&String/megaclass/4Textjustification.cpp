//---

// ### ✅ **Understanding the Problem**

// 1. **Goal:** Format a list of words into justified text such that:

//    * Each line is **exactly `maxWidth` characters**.
//    * **Distribute spaces evenly** between words.
//    * **Left-over spaces** (if not divisible) go more to the **left**.
//    * **Last line** is **left-justified**, not fully justified.

// 2. **Constraints to keep in mind:**

//    * Words are **non-empty**, max 20 characters.
//    * `maxWidth` is up to 100.
//    * Every word fits individually within `maxWidth`.

// ---

// ### 🧠 **Points to Remember While Implementing**

// 1. **Greedy Word Packing:**

//    * Pack as many words as possible **without exceeding `maxWidth`**.
//    * Keep track of `lineLength = total characters + spaces needed`.

// 2. **Three Main Cases:**

//    * **Middle lines with multiple words (justified):**

//      * Distribute spaces between words as evenly as possible.
//      * Extra spaces should go to the **left slots**.
//    * **Lines with one word:**

//      * **Left-justify** and pad the rest with spaces.
//    * **Last line:**

//      * All words are **left-justified**.
//      * Add only **one space** between words.
//      * Pad remaining spaces at the end.

// 3. **Spacing Calculation:**

//    * `totalSpaces = maxWidth - total length of words (without spaces)`
//    * `spacesPerGap = totalSpaces / (words - 1)`
//    * `extraSpaces = totalSpaces % (words - 1)`

// 4. **Use `ostringstream` or `string` for clean string construction.**

// 5. **Loop Control:**

//    * Maintain a current line `start` to `end` range.
//    * When the next word doesn’t fit, **process the current line** and reset.

// 6. **Edge Handling:**

//    * Always **check the last line** and process it separately with left-justification.
//    * Handle **single-word lines** by appending spaces to the right.

// ---

// ### 💡 Example Breakdown

// ```cpp
// Input: ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16

// Output:
// [
//    "This    is    an",      // 4 spaces between words
//    "example  of text",      // 2 spaces between "example" and "of"
//    "justification.  "       // last line left-justified
// ]
// ```

// ---

// ### 🔁 Summary Checklist

// | Task                  | Remember                              |
// | --------------------- | ------------------------------------- |
// | ✅ Greedy word packing | Don't exceed `maxWidth`               |
// | ✅ Space calculation   | Distribute evenly; extra on the left  |
// | ✅ Handle 1-word line  | Left-justify                          |
// | ✅ Handle last line    | Left-justify                          |
// | ✅ Padding             | Always make line length == `maxWidth` |

// ---


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

    // -------------------------
    // Original Example
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = sol.fullJustify(words, maxWidth);
    cout << "Original Test Case:\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    // -------------------------
    // Test Case 2: Single short word
    words = {"Hello"};
    maxWidth = 10;
    result = sol.fullJustify(words, maxWidth);
    cout << "\nTest Case 2 (Single Word):\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    // -------------------------
    // Test Case 3: Exact line fit
    words = {"OpenAI", "GPT", "rocks"};
    maxWidth = 15;
    result = sol.fullJustify(words, maxWidth);
    cout << "\nTest Case 3 (Exact Fit):\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    // -------------------------
    // Test Case 4: One word per line
    words = {"a", "b", "c", "d", "e"};
    maxWidth = 1;
    result = sol.fullJustify(words, maxWidth);
    cout << "\nTest Case 4 (One Word Per Line):\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    // -------------------------
    // Test Case 5: Space distribution
    words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    maxWidth = 16;
    result = sol.fullJustify(words, maxWidth);
    cout << "\nTest Case 5 (Space Distribution):\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    // -------------------------
    // Test Case 6: Large example from LeetCode
    words = {"Science", "is", "what", "we", "understand", "well", "enough", "to",
             "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    maxWidth = 20;
    result = sol.fullJustify(words, maxWidth);
    cout << "\nTest Case 6 (Large Input):\n";
    for (const string &line : result)
        cout << "\"" << line << "\"" << endl;

    return 0;
}
