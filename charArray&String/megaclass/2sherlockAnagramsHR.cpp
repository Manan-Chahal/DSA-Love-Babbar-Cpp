#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Function to count the number of unordered anagrammatic pairs of substrings
int sherlockAndAnagrams(string s)
{
    unordered_map<string, int> anagramatic_substring_count;
    int anagram_pairs = 0; // This will store the final answer

    // Generate all possible substrings
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            // Extract substring from index i to j
            string substring = s.substr(i, j - i + 1);

            // Sort the substring so that all anagrams have the same sorted form
            sort(substring.begin(), substring.end());

            // Count the frequency of each sorted substring
            anagramatic_substring_count[substring]++;
        }
    }

    // For each unique sorted substring, calculate the number of unordered pairs
    for (auto e : anagramatic_substring_count)
    {
        int count = e.second;
        // If a substring occurs 'count' times, the number of ways to pick 2 of them is count * (count - 1) / 2
        anagram_pairs += (count * (count - 1)) / 2;
    }
    return anagram_pairs;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = sherlockAndAnagrams(s);
    cout << "Number of unordered anagrammatic pairs: " << result << endl;

    return 0;
}