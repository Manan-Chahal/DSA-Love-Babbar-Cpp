#include<iostream>
#include<vector>
using namespace std;

// 🟦 PRACTICE SET: POINTERS AND REFERENCES

int main() {

    // 🔹 Q1: Print the value of a using double pointers
    // Expected Output: 50
    int a = 50;
    int* p = &a;
    int** q = &p;
    int** r = q;
    cout << "**Q1 Output:** " << **r << endl;

    // 🟦 PRACTICE SET: sizeof() operator and function parameter behavior

    // 🔹 Q2: Check the size of pointer when passed as an array to a function
    // void solve(int* arr, int size) {
    //     cout << "Q2 Size of pointer parameter in function: " << sizeof(arr) << endl;
    // }
    // int arr[] = {10, 20, 30, 40, 50};
    // int size = 5;
    // solve(arr, size);

    // 🔹 Q3: Check the size of vector when passed by reference
    // void solve(vector<int> &v) {
    //     cout << "Q3 Size of vector reference in function: " << sizeof(v) << endl;
    // }
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // solve(v);

    return 0;
}
