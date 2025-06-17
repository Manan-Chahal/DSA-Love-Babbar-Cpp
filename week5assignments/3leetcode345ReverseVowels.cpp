#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert to lowercase to handle uppercase letters
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // Function to reverse vowels using two-pointer approach
    string reverseVowels(string s) {
        int l = 0;
        int h = s.size() - 1;

        while (l < h) {
            // If both characters at l and h are vowels, swap them
            if (isVowel(s[l]) && isVowel(s[h])) {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            // If left character is not a vowel, move left pointer
            else if (!isVowel(s[l])) {
                l++;
            }
            // If right character is not a vowel, move right pointer
            else {
                h--;
            }
        }

        return s;
    }
};
