#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        int hash[256] = {0};             // Maps each char in s to corresponding char in t
        bool isCharMapped[256] = {0};    // Keeps track of which characters in t are already mapped

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];

            if (hash[sc] == 0 && !isCharMapped[tc]) {
                // If s[i] is not yet mapped and t[i] is not already used
                hash[sc] = tc;           // Map s[i] to t[i]
                isCharMapped[tc] = true; // Mark t[i] as used
            }
            else {
                // If already mapped, check if it's consistent with previous mapping
                if (hash[sc] != tc) {
                    return false;
                }
            }
        }

        return true;
    }
};