#include <iostream>
#include <string>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    // ✅ Method 1: Using Sorting
    bool isAnagramBySorting(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // ✅ Method 2: Using Frequency Table (Counting)
    bool isAnagramByCounting(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int freqTable[256] = {0};

        // Increment for characters in s
        for (int i = 0; i < s.length(); ++i) {
            freqTable[s[i]]++;
        }

        // Decrement for characters in t
        for (int i = 0; i < t.length(); ++i) {
            freqTable[t[i]]--;
        }

        // Check if all values are zero
        for (int i = 0; i < 256; ++i) {
            if (freqTable[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    // Test case 1
    string s1 = "anagram";
    string t1 = "nagaram";

    cout << "Using Sorting -> ";
    cout << (obj.isAnagramBySorting(s1, t1) ? "True" : "False") << endl;

    cout << "Using Counting -> ";
    cout << (obj.isAnagramByCounting(s1, t1) ? "True" : "False") << endl;

    // Test case 2
    string s2 = "rat";
    string t2 = "car";

    cout << "\nUsing Sorting -> ";
    cout << (obj.isAnagramBySorting(s2, t2) ? "True" : "False") << endl;

    cout << "Using Counting -> ";
    cout << (obj.isAnagramByCounting(s2, t2) ? "True" : "False") << endl;

    return 0;
}
