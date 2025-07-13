/*
Leetcode 473: Matchsticks to Square

Problem Statement:
------------------
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick.
You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up.
Return true if you can make this square and false otherwise.

Approach (Your Backtracking Algorithm):
---------------------------------------
- Calculate the total sum and check if it's divisible by 4 (each side must be equal).
- Try to assign each matchstick to one of the 4 sides using recursion.
- For each matchstick, try placing it on each side if it fits.
- Backtrack if a configuration doesn't work.
- Sort matchsticks in descending order to optimize recursion.

Time Complexity:
----------------
- O(4^n), where n is the number of matchsticks (each stick can go to any side).

Space Complexity:
-----------------
- O(n) recursion stack.

Explanation:
------------
- solve: Recursively tries to assign each matchstick to a side. If all sides reach zero, a square is formed.
- makesquare: Checks base conditions, sorts matchsticks, and starts recursion.

Code uses your approach only: classic backtracking, side assignment, and backtracking.

*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Recursive function to try assigning matchsticks to sides
    bool solve(vector<int> &matchsticks, vector<int> &sides, int i)
    {
        if (i == matchsticks.size()) // all matchsticks have been tried
        {
            // If all sides become 0, means we have found 4 equal subsets
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
        }

        bool ans = false;
        // ith matchstick can be a part of A / B / C / D
        for (int j = 0; j < sides.size(); j++)
        {
            if (matchsticks[i] <= sides[j])
            {
                sides[j] -= matchsticks[i]; // include
                ans = ans || solve(matchsticks, sides, i + 1);
                if (ans == true)
                    return true;
                sides[j] += matchsticks[i]; // Backtrack
            }
        }
        return ans;
    }

    // Main function to check if matchsticks can form a square
    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() < 4)
            return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0); // Calculate the total length of all matchsticks
        /*
        Explanation:
        ------------
        - accumulate(matchsticks.begin(), matchsticks.end(), 0) adds up all elements in the matchsticks vector, starting from 0.
        - This gives the total length of all matchsticks.
        - We use this sum to check if it's divisible by 4 (since a square has 4 equal sides).
        - If sum % 4 != 0, it's impossible to form a square, so we return
        */
        if (sum % 4 != 0)
            return false;

        int sideSum = sum / 4;
        vector<int> sides(4, sideSum);

        // Sort in descending order to optimize recursion
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, sides, 0);
    }
};

// Test cases
int main()
{
    Solution sol;

    vector<int> test1 = {1, 1, 2, 2, 2};
    cout << "Test Case 1: {1,1,2,2,2} -> " << (sol.makesquare(test1) ? "True" : "False") << endl; // Expected: True

    vector<int> test2 = {3, 3, 3, 3, 4};
    cout << "Test Case 2: {3,3,3,3,4} -> " << (sol.makesquare(test2) ? "True" : "False") << endl; // Expected: False

    vector<int> test3 = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
    cout << "Test Case 3: {5,5,5,5,4,4,4,4,3,3,3,3} -> " << (sol.makesquare(test3) ? "True" : "False") << endl; // Expected: True

    vector<int> test4 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test Case 4: {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} -> " << (sol.makesquare(test4) ? "True" : "False") << endl; // Expected: True

    vector<int> test5 = {2, 2, 2, 2, 2, 6};
    cout << "Test Case 5: {2,2,2,2,2,6} -> " << (sol.makesquare(test5) ? "True" : "False") << endl; // Expected: False

    return 0;
}

/*
Code uses your approach only: classic backtracking, side assignment, and backtracking.
Time and space complexity are included and explained in comments.
Test cases are provided for various scenarios.
*/