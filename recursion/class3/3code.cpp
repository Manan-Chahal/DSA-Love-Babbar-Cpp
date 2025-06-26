#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution {
public:
    // Recursive function to find min coins needed for 'amount'
    int solve(vector<int>& coins, int amount) {
        // Base Case 1: If amount is 0 → no coin needed
        if (amount == 0) {
            return 0;
        }

        // Base Case 2: If amount goes negative → not a valid way
        if (amount < 0) {
            return INT_MAX;
        }

        int minCoinAns = INT_MAX;

        // Try every coin to find minimum coins needed
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];

            // Only consider if coin is less than or equal to amount
            if (coin <= amount) {
                int recursionAns = solve(coins, amount - coin);

                // If recursion result is valid (not INT_MAX), add this coin
                if (recursionAns != INT_MAX) {
                    minCoinAns = min(minCoinAns, 1 + recursionAns);
                }
            }
        }

        return minCoinAns;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        // If answer is still INT_MAX, means no valid combination
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int amount = 11; // Example amount to make change for

    int result = solution.coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "No valid combination of coins can make the amount." << endl;
    }

    return 0;
}