#include <iostream>   // for input/output
#include <algorithm>  // for fill() and make_pair()

using namespace std;

int main() {
    // -------------------------------
    // PAIR BASICS
    // -------------------------------

    // A pair is a simple container from the STL (Standard Template Library)
    // It stores exactly two heterogeneous values as a single unit.

    // Syntax: pair<datatype1, datatype2> name;
    // Example declarations:

    // pair<int, char> A;                        // declaration only
    // pair<int, char> A(4, 't');                // direct initialization
    // pair<int, char> A = {4, 't'};             // uniform initialization (C++11)
    // pair<int, char> A = make_pair(4, 't');    // using make_pair()

    // Accessing elements of a pair:
    // A.first gives the first element (int)
    // A.second gives the second element (char)
    // Example:
    // cout << A.first << " " << A.second << endl;

    // -------------------------------
    // FILL FUNCTION FOR 2-D ARRAY
    // -------------------------------

    // Declaring and initializing a 4x3 2D array
    int arr[4][3] = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11},
        {12, 13, 14}
    };

    // Now we want to fill the entire 2D array with -1

    // `fill` works on linear (1D) ranges of memory.
    // `&arr[0][0]` is the address of the first element.
    // `&arr[0][0] + (4 * 3)` is the address one past the last element.
    // So this fills all 12 elements of the 2D array with -1.
    fill(&arr[0][0], &arr[0][0] + (4 * 3), -1);

    // Printing the modified array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; // output each element
        }
        cout << endl; // new line after each row
    }

    return 0;
}
