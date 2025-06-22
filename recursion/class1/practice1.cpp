#include<iostream>
using namespace std;

//=====================================
// SUM OF FIRST N NATURAL NUMBERS
// getSum(n) = n + getSum(n-1)
int recursiveSum(int n) {
    // Base Case
    if (n == 1) return 1;

    // Recursive Case
    return recursiveSum(n - 1) + n;
}
//=====================================


//=====================================
// FIBONACCI SERIES
// fib(n) = fib(n-1) + fib(n-2)
int recursiveFibonacci(int n) {
    // Base Case
    if (n == 0 || n == 1) return n;

    // Recursive Case
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}
//=====================================


//=====================================
// POWER OF TWO
// pow(n) = 2 * pow(n-1)
int recursivePowerOfTwo(int n) {
    // Base Case
    if (n == 0) return 1;

    // Recursive Case
    return 2 * recursivePowerOfTwo(n - 1);
}
//=====================================


//=====================================
// COUNTING FROM N TO 1
// Prints n, n-1, ..., 1
void recursiveCounting(int n) {
    // Base Case
    if (n == 0) return;

    // Processing
    cout << n << " ";

    // Recursive Call
    recursiveCounting(n - 1);
}
//=====================================


//=====================================
// FACTORIAL OF N
// fact(n) = n * fact(n-1)
int recursiveFactorial(int n) {
    // Base Case
    if (n == 0 || n == 1) return 1;

    // Recursive Case
    return n * recursiveFactorial(n - 1);
}
//=====================================



int main() {

    // 1. Sum of first N numbers
    cout << "Sum of first 5 numbers: " << recursiveSum(5) << endl;

    // 2. Fibonacci Number
    cout << "9th Fibonacci number: " << recursiveFibonacci(9) << endl;

    // 3. Power of 2^n
    cout << "2^5: " << recursivePowerOfTwo(5) << endl;

    // 4. Counting from n to 1
    cout << "Counting from 5 to 1: ";
    recursiveCounting(5);
    cout << endl;

    // 5. Factorial
    int n = 5;
    cout << "Factorial of " << n << ": " << recursiveFactorial(n) << endl;

    return 0;
}
