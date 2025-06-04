//i will have to try this code with some other approach this does not fit the 
//problem statement 
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
public:
    int divide(int dividendx, int divisorx)
    {
        // Handle overflow case when result would exceed 32-bit signed int range
        if (dividendx == INT_MIN && divisorx == -1)
            return INT_MAX;

        // Determine the sign of the result
        bool ans_pos_sign = true;
        if ((dividendx < 0 && divisorx > 0) || (dividendx > 0 && divisorx < 0))
            ans_pos_sign = false;

        // Convert to positive values using long long to prevent overflow
        long long dividend = static_cast<long long>(dividendx);
        long long divisor = static_cast<long long>(divisorx);

        dividend = abs(dividend);
        divisor = abs(divisor);

        // Apply binary search to find the quotient
        long long s = 0, e = dividend;
        long long ans = 0;

        while (s <= e)
        {
            long long mid = s + ((e - s) >> 1);

            // Check if mid * divisor <= dividend
            if (mid * divisor <= dividend)
            {
                ans = mid;
                s = mid + 1; // try for a bigger value
            }
            else
            {
                e = mid - 1; // try for a smaller value
            }
        }

        // Apply the correct sign to the result
        if (!ans_pos_sign)
            return -ans;

        return ans;
    }
};

// Driver code for testing
int main()
{
    Solution sol;
    int dividend = -2147483648;
    int divisor = 2;

    int result = sol.divide(dividend, divisor);
    cout << "Result: " << result << endl;

    return 0;
}
