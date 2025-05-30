// ✅ Problem: Find the square root of a number n up 
//to high precision (e.g. 9 decimal places),
// without using built-in functions like sqrt().

#include <iostream>
#include <algorithm>
using namespace std;

// Function to compute integer part of square root using Binary Search
int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;

    while (s <= e)
    {
        int mid = (s + e) >> 1; // Same as (s + e) / 2

        // If mid*mid is less than or equal to n, it's a candidate
        if (mid * mid <= n)
        {
            ans = mid;   // store current mid as answer
            s = mid + 1; // move right to find a better answer
        }
        else
            e = mid - 1; // move left
    }

    return ans;
}

// Function to get square root of a number with precision using brute-force increment
double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n); // Step 1: Get integer part of square root

    int precision = 9; // Total decimal places needed
    double step = 0.1; // Start increment step with 0.1

    while (precision--)
    {
        double j = sqrt; // Start from current sqrt estimate

        // Increment j until j*j exceeds n
        while (j * j <= n)
        {
            sqrt = j;  // Update sqrt to current j
            j += step; // Move to next step
        }

        step /= 10; // Decrease step size for next decimal place
    }

    return sqrt;
}

// Function to get square root using Binary Search with double values
double BSPrecision(int n)
{
    double start = 0;
    double end = n;
    double ans = 0;

    // Loop runs while the difference is greater than required precision
    while ((end - start) > 0.000000001)
    {
        double mid = (start + end) / 2;
        double sqr = mid * mid;

        if (sqr <= n)
        {
            ans = mid;                                   // Store result
            start = mid + 0.000000000000000000000000001; // go right
        }
        else
            end = mid - 0.000000000000000000000000001; // go left
    }

    return ans;
}

int main()
{
    int n = 63;

    // Method 1: Step-by-step incremental precision
    double ans = myPrecisionSqrt(n);
    printf("M1: Precision Sqrt: %.9f\n", ans); // Print with 9 decimal precision

    // Method 2: Using Binary Search with double values
    ans = BSPrecision(n);
    printf("M2: Precision Sqrt: %.9f\n", ans);

    return 0;
}
