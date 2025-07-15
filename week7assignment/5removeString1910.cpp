#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Recursive helper function to remove all occurrences of 'part' from 's'
    void remove0CCRE(string &s, string &part) {
        int found = s.find(part); // Find the index where 'part' starts in 's'
        if (found != string::npos) {
            // Remove it
            string left_part = s.substr(0, found); // Part before 'part'
            string right_part = s.substr(found + part.size()); // Part after 'part'
            s = left_part + right_part; // Concatenate left and right parts
            remove0CCRE(s, part); // Recursive call to remove next occurrence
        } else {
            // base case reached, no more occurrences found
            return;
        }
    }

    // Main function to remove all occurrences of 'part' from 's'
    string removeOccurrences(string s, string part) {
        remove0CCRE(s, part); // Call recursive function
        return s; // Return the result after all removals
    }
};

// Test cases
int main() {
    Solution sol;
    cout << sol.removeOccurrences("daabcbaabcbc", "abc") << endl; // Output: "dab"
    cout << sol.removeOccurrences("axxxxyyyyb", "xy") << endl;    // Output: "axxxxb"
    cout << sol.removeOccurrences("ababab", "ab") << endl;        // Output: ""
    cout << sol.removeOccurrences("hellohello", "hello") << endl; // Output: ""
    cout << sol.removeOccurrences("mississippi", "iss") << endl;  // Output: "mippi"
    return 0;
}

/*
Explanation:
------------
- remove0CCRE: Recursively finds and removes all occurrences of 'part' from 's'.
- removeOccurrences: Entry point for removal.
- main: Runs several test cases and prints results.

Time Complexity: O(N*K), where N is the length of s and K is the number of occurrences.
Space Complexity: O(K) due to recursion stack space.
*/
