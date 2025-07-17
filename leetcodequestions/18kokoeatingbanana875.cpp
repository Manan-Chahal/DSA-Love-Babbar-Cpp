#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Helper function to check if Koko can finish all bananas with a given speed k within h hours
    bool canKokoFinishBananasWithKSpeed(vector<int> &piles, int h, int k)
    {
        long long int totalHoursTakenByKokoToFinishAllBananas = 0;

        // Calculate how many hours she would take with current speed k
        for (int i = 0; i < piles.size(); i++)
        {
            // Koko eats ceil(piles[i] / k) hours per pile
            totalHoursTakenByKokoToFinishAllBananas += ceil(piles[i] / (double)k);
        }

        // If total time is within allowed hours, return true
        return totalHoursTakenByKokoToFinishAllBananas <= h;
    }

    // Main function to find the minimum speed at which Koko can eat all bananas
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1; // Minimum possible speed
        int end = *max_element(piles.begin(), piles.end()); // Maximum pile size (worst-case speed)
        int ans = 0;

        // Binary search over speed k
        // Time Complexity: O(log(max(piles)) * n)
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            int k = mid;

            // Check if current speed k is sufficient
            if (canKokoFinishBananasWithKSpeed(piles, h, k))
            {
                // Speed k works, but try to find smaller (minimum) speed
                ans = k;
                end = mid - 1;
            }
            else
            {
                // Speed k is too slow, try a faster speed
                start = mid + 1;
            }
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
