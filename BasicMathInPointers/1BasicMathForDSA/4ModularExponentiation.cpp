// ### 🧾 Problem Statement:

// **Implement `PowMod(x, n, M)`**, which calculates:

// > $(x^n) \mod M$

// * Where:

//   * `x` is the base,
//   * `n` is the exponent,
//   * `M` is the modulus.

// Use an **efficient algorithm** to do so — ideally **Binary Exponentiation** or **Fast Power Modulo** technique.

// ---

// ### ✅ Full C++ Code with Detailed Comments:

// ```cpp
class Solution {
public:
    long long int PowMod(long long int x, long long int n, long long int M) {
        // Initialize the result variable to 1
        long long int ans = 1;

        // We will keep reducing the power 'n' until it becomes 0
        while (n > 0) {
            // (n & 1) checks if the last bit of n is 1, i.e., if n is odd
            if (n & 1) {
                // If the power is odd, multiply current base with result
                // We also apply % M to keep the result within bounds
                ans = (ans * x) % M;
            }

            // Now we square the base (x = x^2)
            // 1LL * x * x is used to avoid integer overflow
            x = (1LL * x * x) % M;

            // Divide n by 2 (integer division) using right shift
            // Equivalent to: n = n / 2
            n >>= 1;
        }

        // Finally return the answer modulo M
        return ans % M;
    }
};


// ### 🧠 Key Concepts Explained:

// | Line                     | Concept                                                                |
// | ------------------------ | ---------------------------------------------------------------------- |
// | `if (n & 1)`             | Check if `n` is **odd**. Bitwise AND with 1 checks the last bit.       |
// | `ans = (ans * x) % M;`   | Multiply base when exponent is odd and take `% M` to avoid overflow.   |
// | `x = (1LL * x * x) % M;` | Square the base for the next iteration. Use `1LL` to prevent overflow. |
// | `n >>= 1;`               | Right shift: divide `n` by 2 efficiently (removes the last bit).       |

// ---

// ### 🧪 Example Dry Run:

// **Input:**

// ```cpp
// x = 3, n = 5, M = 13
// ```

// **Steps:**

// 1. Binary of `n = 5` is `101`.
// 2. Loop:

//    * `n = 5 (101)`: odd → `ans = (1 * 3) % 13 = 3`, `x = 9`, `n = 2`
//    * `n = 2 (010)`: even → skip mult, `x = 81 % 13 = 3`, `n = 1`
//    * `n = 1 (001)`: odd → `ans = (3 * 3) % 13 = 9`, `x = 9`, `n = 0`
// 3. Loop ends.

// ✅ Final result: `9`

// ---