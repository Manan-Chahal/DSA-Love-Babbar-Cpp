// 🔍 Exponential Search vs Unbounded Binary Search

// -----------------------------------------------
// 1️⃣ Exponential Search
// -----------------------------------------------

// ✅ When to Use:
// - Works on sorted arrays with KNOWN size
// - Useful when the element is likely near the beginning

// 🕒 Time Complexity:
// - Finding Range: O(log p)
// - Binary Search: O(log p)
// - ✅ Total: O(log p), where p = index of target

// 💡 Key Step:
// - Start with i = 1, keep doubling: i = 2, 4, 8, ...
// - Once arr[i] >= target, binary search in [i/2, min(i, n-1)]

// -----------------------------------------------
// 2️⃣ Unbounded Binary Search
// -----------------------------------------------

// ✅ When to Use:
// - Works on sorted arrays/streams with UNKNOWN size
// - Size can't be accessed, you use a get(index) function
// - Simulate infinity using INT_MAX or similar if out-of-bounds

// 🕒 Time Complexity:
// - Finding Range: O(log p)
// - Binary Search: O(log p)
// - ✅ Total: O(log p), where p = index of target

// 💡 Key Step:
// - Start with end = 1, double it until arr[end] >= target
// - Binary search in range [end/2, end]

// -----------------------------------------------
// 📊 Comparison Table
// -----------------------------------------------

// | Feature            | Exponential Search            | Unbounded Binary Search             |
// |--------------------|-------------------------------|-------------------------------------|
// | Input Type         | Sorted array (known size)     | Sorted array/stream (unknown size)  |
// | Purpose            | Quick search near start       | Search in infinite/unknown data     |
// | Range Expansion    | i = 1 → 2 → 4 → 8 → ...       | end = 1 → 2 → 4 → 8 → ...           |
// | Search Type        | Binary Search after range     | Binary Search after range           |
// | Time Complexity    | O(log p)                      | O(log p)                            |

// -----------------------------------------------
// ✅ Summary
// Both algorithms have O(log p) time but differ in usage:
// - Exponential Search: When size is known
// - Unbounded Binary Search: When size is unknown
