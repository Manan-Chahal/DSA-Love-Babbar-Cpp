#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Helper function to check if we can make m bouquets using exactly k adjacent flowers each on day D
    bool canWeMakeMBouquetsWithDDays(vector<int> &bloomDay, int m, int k, int D)
    {
        int counter = 0; // counts adjacent bloomed flowers
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // Check if the flower at index i is bloomed on or before day D
            if (bloomDay[i] <= D)
            {
                counter++; // flower is usable
            }

            // If we've collected k flowers, we can make one bouquet
            if (counter == k)
            {
                m--;        // made one bouquet
                counter = 0; // reset for the next bouquet
                if (m == 0)
                    break; // made enough bouquets
            }

            // If the flower isn't bloomed, reset the adjacent counter
            if (bloomDay[i] > D)
                counter = 0;
        }

        // Check if we were able to make m bouquets
        return m == 0;
    }

    // Main function to find the minimum number of days required to make m bouquets
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // Early return: Not enough flowers to make the bouquets
        long long requirement = (long long)m * (long long)k;
        if (bloomDay.size() < requirement)
            return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end()); // min possible days
        int end = *max_element(bloomDay.begin(), bloomDay.end());   // max possible days
        int ans = 0;

        // Binary search on the minimum number of days
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            int day = mid;

            // Check if we can make the bouquets in 'day' days
            if (canWeMakeMBouquetsWithDDays(bloomDay, m, k, day))
            {
                ans = mid;      // possible answer found
                end = mid - 1;  // try to minimize further
            }
            else
            {
                start = mid + 1; // try more days
            }
        }

        return ans;
    }
};
