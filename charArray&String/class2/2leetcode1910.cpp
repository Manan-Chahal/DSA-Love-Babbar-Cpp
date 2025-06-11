#include <iostream>
#include <string>
using namespace std;

class Solution { // TC = O(n/k(n-k)); 
public:
    string removeOccurrences(string full, string pattern) {
        // Keep removing the pattern as long as it is found in the string
        while (full.find(pattern) != string::npos) {
            // full.find(pattern) gives the index of first occurrence of pattern
            // full.erase(start_index, number_of_characters_to_remove)
            full.erase(full.find(pattern), pattern.length());
        }
        return full;
    }
};

int main() {
    Solution obj;
    
    // Example input
    string full = "aabababa";
    string pattern = "aba";
    
    // Calling the function
    string result = obj.removeOccurrences(full, pattern);

    // Output the result
    cout << "Result after removing pattern: " << result << endl;

    return 0;
}
// ### 🧠 Code Summary

// ```cpp
// while (full.find(pattern) != string::npos) {
//     full.erase(full.find(pattern), pattern.length());
// }
// ```

// You are:

// 1. Repeatedly calling `full.find(pattern)` to locate the next occurrence of the pattern.
// 2. Then calling `full.erase()` to remove that pattern from the string.

// ---

// ### 🔎 Step-by-Step Time Complexity Analysis

// Let:

// * `n` = length of the initial full string
// * `k` = length of the pattern

// ---

// #### 🌀 Loop Runs How Many Times?

// * Every time you **successfully find and remove** a `pattern` of length `k`, you are reducing the string’s length by `k`.
// * So, in the **worst case**, this loop can run at most `n / k` times.

// ✅ **Number of iterations = O(n / k)**

// ---

// #### 🧾 What Happens Inside the Loop?

// * `full.find(pattern)`:

//   * Worst case: it scans through almost the entire string each time ⇒ **O(n)** (because `find` is linear)
// * `full.erase(start, k)`:

//   * Erasing `k` characters from the middle of a C++ `std::string` involves shifting all characters after the erased part ⇒ **O(n)** (in worst case)

// ⚠️ BUT the string is **shrinking** over time.

// * So we don’t always operate on full `n` length; it gradually drops toward `n - k`.

// ✅ So **on average**, each iteration takes about **O(n - k)** time.

// ---

// ### 📊 Final Time Complexity = O((n / k) × (n - k))

// * Because:

//   * `n / k` iterations
//   * Each iteration takes about `O(n - k)` time (find + erase)

// ---

// ### 📦 Simplified Approximation

// In terms of big-O, when `k` is small compared to `n`, say constant, this becomes:

// $$
// O\left( \frac{n}{k} \times (n - k) \right) = O\left( \frac{n(n - k)}{k} \right) \approx O(n^2 / k)
// $$

// If `k` ≈ constant → time complexity ≈ **O(n²)**

// ---

// ### 🧪 Example Walkthrough

// Let’s say:

// * `full = "aabababa"` → length `n = 8`
// * `pattern = "aba"` → length `k = 3`

// **Pass 1**:

// * `"aba"` found at index 1 → remove → string becomes `"ababa"`

// **Pass 2**:

// * `"aba"` found at index 0 → remove → string becomes `"ba"`

// **Pass 3**:

// * No `"aba"` found → exit

// ➡️ 2 iterations × about 5–6 operations each = total \~10–12 operations

// This matches **(n / k) × (n - k)** in behavior.

// ---

// ### ✅ Final Verdict

// ```cpp
// Time Complexity: O((n / k) × (n - k))
//                = O(n² / k) approximately
// Space Complexity: O(1) auxiliary (modifies the string in-place)
// ```

// Let me know if you want the **optimized approach** using a stack or `std::string` as a simulated stack (linear time)!

