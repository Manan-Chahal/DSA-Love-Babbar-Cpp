class Solution {
public:

    // Recursive helper function to remove all occurrences of 'part' from 's'
    void remove0CCRE(string &s, string &part) {
        int found = s.find(part); // Find the index where 'part' starts in 's'

        if (found != string::npos) {
            // part string has been located.

            // Please remove it
            string left_part = s.substr(0, found); // Take part of string before 'part'
            string right_part = s.substr(found + part.size()); // Take part after 'part'

            s = left_part + right_part; // Concatenate left and right parts (removing 'part')

            remove0CCRE(s, part); // Recursive call to remove next occurrence
        }
        else {
            // base case reached, no more occurrences found
            return; // all the occurrences of 'part' have been removed
        }
    }

    string removeOccurrences(string s, string part) {
        remove0CCRE(s, part); // Call recursive function
        return s; // Return the result after all removals
    }
};
