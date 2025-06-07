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
https://github.com/Manan-Chahal/DSA-Love-Babbar-Cpp/commit/9d0a6d93f87bfc9cfef932e78f87070d1c1e30ef