#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Custom comparator to sort numbers based on combination logic
    static bool mycomp(string a, string b) {
        string t1 = a + b;
        string t2 = b + a;
        // Return true if t1 should come before t2 for largest number
        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        
        // Convert all numbers to strings
        for (auto n : nums) {
            snums.push_back(to_string(n));
        }

        // Sort using custom comparator
        sort(snums.begin(), snums.end(), mycomp);

        // If after sorting, the largest number is "0", return "0"
        if (snums[0] == "0") return "0";

        // Concatenate all sorted strings to form the result
        string ans = "";
        for (auto str : snums) {
            ans += str;
        }

        return ans;
    }
};
