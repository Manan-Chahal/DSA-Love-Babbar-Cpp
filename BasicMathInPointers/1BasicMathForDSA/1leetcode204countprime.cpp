#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1️⃣ Naive Approach: O(n * sqrt(n))
bool isPrimeNaive(int num) {
    if (num < 2) return false;
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int countPrimesNaive(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrimeNaive(i)) count++;
    }
    return count;
}

// 2️⃣ Optimized Naive: O(n * sqrt(n)) but faster in practice
bool isPrimeOptimized(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int countPrimesOptimized(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrimeOptimized(i)) count++;
    }
    return count;
}

// 3️⃣ Sieve of Eratosthenes: O(n log log n)
int countPrimesSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) count++;
    }
    return count;
}

int main() {
    int n = 300000; // You can change this value to test with different limits

    cout << "Counting primes up to " << n << "...\n\n";

    // Naive
    int naiveCount = countPrimesNaive(n);
    cout << "1. Naive Approach: " << naiveCount << " primes found\n";

    // Optimized Naive
    int optimizedCount = countPrimesOptimized(n);
    cout << "2. Optimized Naive: " << optimizedCount << " primes found\n";

    // Sieve of Eratosthenes
    int sieveCount = countPrimesSieve(n);
    cout << "3. Sieve of Eratosthenes: " << sieveCount << " primes found\n";

    return 0;
}
