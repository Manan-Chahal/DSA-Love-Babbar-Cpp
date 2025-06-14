// 📝 Problem: Sort Pairs by Second Element
// Problem Description:

// Write a program that reads a list of integer pairs (a, b) (i.e., a two-dimensional vector where each sub-vector contains exactly two integers). Your goal is to sort the list of pairs in descending order based on the second element b of each pair, and then print the sorted result.

// 📥 Input Format:
// First, read an integer n, the number of pairs.

// Then read n lines, each containing two integers a and b.

// 📤 Output Format:
// Print the list of pairs before sorting, each pair on a separate line:
// a b

// Print the list of pairs after sorting descending by b, each on a separate line:
// a b

// 🔁 Constraints:
// 1 ≤ n ≤ 10^5 (adjust as needed)

// Integers a and b are within the range of standard 32-bit signed integers.

// 🧠 Example:
// Input:
// 4
// 1 5
// 2 3
// 3 9
// 4 1
// Output:
// Here are the values before sorting:
// 1 5
// 2 3
// 3 9
// 4 1

// Sorting based on second element in descending order...

// Here are the values after sorting:
// 3 9
// 1 5
// 2 3
// 4 1
// 🚀 Code Highlights:
// printvv: Prints each pair in the list.

// mycompfor1stIndex: Comparator that sorts by the second element in descending order.

// sort(v.begin(), v.end(), mycompfor1stIndex): Sorts using the custom comparator.


#include <algorithm> // for sort
#include <iostream>  // for input-output
#include <vector>    // for vector

using namespace std;

// Function to print a 1D vector
void print(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

// Function to print a 2D vector (vector of pairs)
void printvv(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); ++i) {
    vector<int> &temp = v[i]; // reference to ith row
    int a = temp[0];
    int b = temp[1];
    cout << a << " " << b << endl;
  }
  cout << endl;
}

// Custom comparator for sorting 2D vectors based on 2nd element in DESC order
bool mycompfor1stIndex(vector<int> &a, vector<int> &b) {
  return a[1] > b[1]; // Sort by second element in descending order
  // To sort in ascending order, use: return a[1] < b[1];
}

int main() {
  vector<vector<int>> v;
  int n;

  // Input: size of the 2D vector
  cout << "Enter size:\n";
  cin >> n;

  // Taking input for each sub-vector
  for (int i = 0; i < n; ++i) {
    int a, b;
    cout << "Enter values a and b:\n";
    cin >> a >> b;
    vector<int> temp;
    temp.push_back(a); // First element
    temp.push_back(b); // Second element
    v.push_back(temp); // Push row to main vector
  }

  // Show original data
  cout << "\nHere are the values before sorting:\n";
  printvv(v);

  // Sort using custom comparator
  cout << "Sorting based on second element in descending order...\n";
  sort(v.begin(), v.end(), mycompfor1stIndex);

  // Show sorted data
  cout << "\nHere are the values after sorting:\n";
  printvv(v);

  return 0;
}
// 📝 Explanation of the Code
//  1. main() Function Begins
// This is where everything starts.
// vector<vector<int>> v;
// int n;
// These variables are declared to store your 2D vector v and the number of rows (n = number of pairs).

// 🖊️ 2. Input from User
// cin >> n;
// User enters:

// 4
// Then we enter the loop:

// cpp
// Copy
// Edit
// for (int i = 0; i < n; ++i) {
//   int a, b;
//   cin >> a >> b;
//   ...
// }
// User enters:

// Copy
// Edit
// 1 5
// 2 3
// 3 9
// 4 1
// These are stored as:

// cpp
// Copy
// Edit
// v = {
//   {1, 5},
//   {2, 3},
//   {3, 9},
//   {4, 1}
// };
// 👀 3. Call to printvv(v)
// cpp
// Copy
// Edit
// printvv(v);
// This function prints each pair in its own line:

// cpp
// Copy
// Edit
// for (int i = 0; i < v.size(); ++i) {
//   vector<int> &temp = v[i];
//   cout << temp[0] << " " << temp[1] << endl;
// }
// Output:

// sql
// Copy
// Edit
// Here are the values before sorting:
// 1 5
// 2 3
// 3 9
// 4 1
// 🔁 4. Sorting Using Custom Comparator
// cpp
// Copy
// Edit
// sort(v.begin(), v.end(), mycompfor1stIndex);
// Now we sort using this comparator:

// cpp
// Copy
// Edit
// bool mycompfor1stIndex(vector<int> &a, vector<int> &b) {
//   return a[1] > b[1];  // Sort based on 2nd value (descending)
// }
// How It Works:
// Compares a[1] and b[1] (the second element of each pair).

// Sorts in descending order (>).

// Internally, sort compares:

// scss
// Copy
// Edit
// Compare (1,5) and (2,3) → 5 > 3 → keep order
// Compare (2,3) and (3,9) → 3 < 9 → swap
// ...
// After sorting, v becomes:

// cpp
// Copy
// Edit
// v = {
//   {3, 9},
//   {1, 5},
//   {2, 3},
//   {4, 1}
// };
// 📤 5. Second Call to printvv(v)
// cpp
// Copy
// Edit
// printvv(v);
// Now it prints the sorted version:

// Output:

// sql
// Copy
// Edit
// Here are the values after sorting:
// 3 9
// 1 5
// 2 3
// 4 1
// 🧠 Summary Table
// Step	What happens	Function Used
// Input n, then pairs	User inputs 4 pairs	main()
// Store pairs in v	2D vector stores each pair	main()
// Print original values	Each pair is printed	printvv()
// Sort based on 2nd element	Descending sort on second value of pairs	sort() + mycomp...()
// Print sorted values	Sorted list is printed	printvv()