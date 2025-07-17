#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // List of Roman numerals in descending order of value
        string romanSymbols[] = {
            "M", "CM", "D", "CD", "C", "XC",
            "L", "XL", "X", "IX", "V", "IV", "I"
        };

        // Corresponding integer values for the Roman numerals
        int values[] = {
            1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1
        };

        string ans = ""; // final answer to build

        // Iterate over all roman numeral values
        for (int i = 0; i < 13; i++) {
            // While current value can fit in the number
            while (num >= values[i]) {
                ans += romanSymbols[i]; // Append the roman symbol
                num -= values[i];       // Reduce the number
            }
        }

        return ans;
    }
};
