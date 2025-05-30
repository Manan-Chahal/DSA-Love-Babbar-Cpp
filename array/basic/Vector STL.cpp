#include <iostream>
#include <vector>
using namespace std;

// 1. Printing the Vector Using Index-Based Loop
void print(const vector<int>& v) {
    cout << "Printing vector (index-based):" << endl;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 2. Printing the Vector Using Range-Based Loop
void print2(const vector<int>& v) {
    cout << "Printing vector (range-based):" << endl;
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    // Creating a vector and adding elements
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // Printing vector using two methods
    print(v);
    print2(v);

    // 4. Accessing Front and Back Elements (Uncomment to use)
    // cout << "Front element: " << v.front() << endl;
    // cout << "End element: " << v.back() << endl;

    // 5. Vector Initialization with Specific Values (Uncomment to use)
    // vector<int> arr2(5, -1); // Initialize with 5 elements of value -1
    // print(arr2);

    // 6. Pop Back Operation (Uncomment to use)
    // vector<int> arr3 = {1, 2, 3, 4, 5}; // Initialize vector with values
    // arr3.pop_back(); // Remove last element
    // print(arr3);

    // 7. Copying Vectors (Uncomment to use)
    // vector<int> arr5 = {1, 2, 3, 4, 5};
    // vector<int> arr6(arr5); // Copying arr5 to arr6
    // print(arr6);

    // 8. Vector Insertion Through User Input (Uncomment to use)
    // vector<int> v;
    // int n;
    // cout << "Enter number of elements: ";
    // cin >> n; // User specifies number of elements
    // for (int i = 0; i < n; ++i) {
    //     int d;
    //     cin >> d;
    //     v.push_back(d); // Insert elements dynamically
    // }
    // print(v);

    // 9. Clearing and Re-Inserting Values (Uncomment to use)
    // v.clear(); // Clear all elements
    // v.push_back(50); // Add new element
    // print(v);

    // 10. Removing the Last Element (Uncomment to use)
    // v.pop_back();
    // print(v);

    return 0;
}
