#include <iostream>
#include <vector>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

class Solution {
public:

    // Recursive function to find max profit
    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
        // Base case: reached end of the prices array
        if (i == prices.size()) return;

        // Solution for one case
        if (prices[i] < minPrice) 
            minPrice = prices[i]; // update min price so far

        int todaysProfit = prices[i] - minPrice; // profit if bought at minPrice and sold today

        if (todaysProfit > maxProfit) 
            maxProfit = todaysProfit; // update maxProfit if today's profit is better

        // Recursive call for next day
        maxProfitFinder(prices, i + 1, minPrice, maxProfit);
    }

    // Wrapper function
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        maxProfitFinder(prices, 0, minPrice, maxProfit);

        return maxProfit;
    }
};

// Test cases
int main() {
    Solution sol;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Test 1): " << sol.maxProfit(prices1) << endl; // Output: 5

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit (Test 2): " << sol.maxProfit(prices2) << endl; // Output: 0

    vector<int> prices3 = {2, 4, 1};
    cout << "Max Profit (Test 3): " << sol.maxProfit(prices3) << endl; // Output: 2

    vector<int> prices4 = {1, 2};
    cout << "Max Profit (Test 4): " << sol.maxProfit(prices4) << endl; // Output: 1

    vector<int> prices5 = {3, 2, 6, 5, 0, 3};
    cout << "Max Profit (Test 5): " << sol.maxProfit(prices5) << endl; // Output: 4

    return 0;
}

/*
Time Complexity: O(N)
- Each day is processed once in the recursion.

Space Complexity: O(N)
- Due to recursion stack (one call per day).
*/
