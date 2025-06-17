#include <iostream>

using namespace std;

// Define the modulo value (usually 1e9+7 in problems to avoid overflow)
const int M = 1e9 + 7;

// Fast Exponentiation using Binary Exponentiation
int fastExponentiation(int x, int n)
{
    long long int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // If n is odd, multiply current base with result
            ans = (ans * x) % M;
        }

        // Square the base and divide the power by 2
        x = (1LL * x * x) % M;
        n >>= 1; // Right shift n by 1 (equivalent to n = n / 2)
    }

    return ans % M;
}

// Slow (naive) exponentiation: O(n)
int slowExponentiation(int a, int b)
{
    int ans = 1;
    while (b--)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    int a = 5;
    int b = 4;

    cout << "Slow Exponentiation (without modulo): " << slowExponentiation(a, b) << endl;
    cout << "Fast Exponentiation (with modulo): " << fastExponentiation(a, b) << endl;

    return 0;
}
