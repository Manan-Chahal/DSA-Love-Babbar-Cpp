#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
#include <string>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int beautySum = 0; // final result

        // Loop through every possible starting index of the substring
        for (int i = 0; i < s.size(); i++)
        {
            // We'll use a fixed-size frequency array for lowercase characters ('a' to 'z')
            int mp[256] = {0}; // using size 256 for safety, though only 'a' to 'z' are used

            // Loop through every possible ending index from current i
            for (int j = i; j < s.size(); j++)
            {
                char &ch = s[j]; // current character
                mp[ch]++;        // increase its frequency

                int mini = INT_MAX; // to store minimum frequency of any present character
                int maxi = INT_MIN; // to store maximum frequency of any present character

                // Iterate only from 'a' to 'z' to check frequency
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (mp[c] > 0)
                    { // only consider characters that are part of the current substring
                        maxi = max(maxi, mp[c]);
                        mini = min(mini, mp[c]);
                    }
                }

                // Calculate beauty for this substring and add to total
                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};
