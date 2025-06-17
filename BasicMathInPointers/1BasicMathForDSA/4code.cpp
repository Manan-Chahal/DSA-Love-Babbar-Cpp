#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    #define M 1000000007

    // Step 1: Standard Sieve to get all primes up to sqrt(R)
    vector<bool> Sieve(long long int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        for (long long int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (long long int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return sieve;
    }

    // Step 2: Segmented Sieve for range [L, R]
    vector<bool> segmentedSeive(long long int L, long long int R) {
        vector<bool> baseSieve = Sieve(sqrt(R));
        vector<long long int> basePrimes;

        for (long long int i = 0; i < baseSieve.size(); i++) {
            if (baseSieve[i]) basePrimes.push_back(i);
        }

        vector<bool> segSieve(R - L + 1, true);
        if (L == 1) segSieve[0] = false;

        for (auto prime : basePrimes) {
            long long int firstMultiple = max(prime * prime, ((L + prime - 1) / prime) * prime);
            for (long long int j = firstMultiple; j <= R; j += prime) {
                segSieve[j - L] = false;
            }
        }

        return segSieve;
    }

    // Step 3: Final Function to return product of primes in range [L, R]
    long long primeProduct(long long L, long long R) {
        vector<bool> segSieve = segmentedSeive(L, R);
        long long int ans = 1;

        for (long long int i = 0; i < segSieve.size(); i++) {
            if (segSieve[i]) {
                long long int prime = (L + i) % M;
                ans = (ans * prime) % M;
            }
        }

        return ans;
    }
};
