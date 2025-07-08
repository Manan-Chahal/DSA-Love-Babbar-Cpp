#include <iostream>
using namespace std;

//------------------- 1. Pass by Value (No Backtrack Needed) -------------------
void printPermutationByValue(string str, int i) {
  // Base case: If all positions are fixed, print the permutation
  if (i >= str.length()) {
    cout << str << endl;
    return;
  }
  for (int j = i; j < str.length(); j++) {
    swap(str[i], str[j]); // Give each character a chance at position i
    printPermutationByValue(str, i + 1); // Recursively fix the next position
    // No need to swap back, as str is a copy in this function call
  }
}

//------------------- 2. Pass by Reference (No Backtrack - WRONG!) -------------------
void printPermutationWrong(string &str, int i) {
  // Base case: If all positions are fixed, print the permutation
  if (i >= str.length()) {
    cout << str << endl;
    return;
  }
  for (int j = i; j < str.length(); j++) {
    swap(str[i], str[j]);
    printPermutationWrong(str, i + 1);
    // MISSING: swap(str[i], str[j]); // Not swapping back is WRONG for reference!
    // This will cause incorrect, duplicate, or missing permutations.
  }
  /*
  Why is this wrong?
  ------------------
  - Since str is passed by reference, every swap changes the original string for all recursive calls.
  - If you don't swap back after recursion, the next iteration of the loop works on a modified string,
    not the original one for this recursion level.
  - This causes incorrect, duplicate, or missing permutations.
  - Always backtrack (swap back) when using reference!
  */
}
//------------------- 3. Pass by Reference (Backtrack Required) -------------------
void printPermutationByReference(string &str, int i) {
  // Base case: If all positions are fixed, print the permutation
  if (i >= str.length()) {
    cout << str << endl;
    return;
  }
  for (int j = i; j < str.length(); j++) {
    swap(str[i], str[j]); // Give each character a chance at position i
    printPermutationByReference(str, i + 1); // Recursively fix the next position
    swap(str[i], str[j]); // Backtrack: restore the string for the next iteration
  }
}

int main() {
  cout << "1. Pass by Value (No Backtrack Needed):" << endl;
  string str1 = "abc";
  printPermutationByValue(str1, 0);

  cout << "\n2. Pass by Reference (No Backtrack - WRONG!):" << endl;
  string str2 = "abc";
  printPermutationWrong(str2, 0);

  cout << "\n3. Pass by Reference (Backtrack Required):" << endl;
  string str3 = "abc";
  printPermutationByReference(str3, 0);

  return 0;
}