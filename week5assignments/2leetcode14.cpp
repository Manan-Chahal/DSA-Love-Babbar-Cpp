// ```cpp
// for (auto str : strs) {
// ```

// ---

// ### ✅ What it does:

// This is a **range-based for loop** in C++ (introduced in C++11). It **iterates over all elements** of the container `strs`, where:

// * `strs` is a `vector<string>`, meaning a list of strings.
// * Each element `str` will represent one string from the vector `strs`.

// ---

// ### 🧠 Breakdown:

// Let’s say you have:

// ```cpp
// vector<string> strs = {"flower", "flow", "flight"};
// ```

// The loop:

// ```cpp
// for (auto str : strs)
// ```

// Will run **3 times** and `str` will be:

// * First iteration: `"flower"`
// * Second iteration: `"flow"`
// * Third iteration: `"flight"`

// ---

// ### ❓Why `auto`?

// `auto` automatically detects the type of each element in the container. Since `strs` is a `vector<string>`, `auto` here is deduced as `string`.

// You could also write it as:

// ```cpp
// for (string str : strs)
// ```

// ---

// ### ⚠️ Important Note:

// This loop **copies** each string into `str`. So if you modify `str`, it won’t affect the original string in `strs`.

// If you want to avoid unnecessary copying (especially with large strings), use **reference**:

// ```cpp
// for (const string& str : strs)
// ```

// This version:

// * Avoids copy (more efficient).
// * Uses `const` since we don’t want to change the original strings.

// ---

// ### ✅ Summary:

// | Syntax                  | Meaning                                 |
// | ----------------------- | --------------------------------------- |
// | `for (auto str : strs)` | Loop through each string in `strs`      |
// | `auto`                  | Automatically infers type as `string`   |
// | `str`                   | A copy of each string (one at a time)   |
// | `const string& str`     | Efficient: no copy, read-only reference |

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0; // index for character position

        while (true) {
            char curr_ch = 0; // placeholder for the current character

            // iterate over all strings
            for (auto str : strs) {
                // Out of bounds for this string
                if (i >= str.size()) {
                    curr_ch = 0;
                    break;
                }

                // First string, set current character
                if (curr_ch == 0) {
                    curr_ch = str[i];
                }
                // Compare with the character at same position in other strings
                else if (str[i] != curr_ch) {
                    curr_ch = 0;
                    break;
                }
            }

            // No match found or out of bounds
            if (curr_ch == 0) {
                break;
            }

            // If valid match found, add to answer
            ans.push_back(curr_ch);
            i++; // check next character
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << obj.longestCommonPrefix(strs1) << endl;

    // Example 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << obj.longestCommonPrefix(strs2) << endl;

    return 0;
}
