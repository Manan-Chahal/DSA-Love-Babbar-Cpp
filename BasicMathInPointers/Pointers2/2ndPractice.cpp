#include<iostream>
using namespace std;

int main() {

    /*
    🟦 PRACTICE SET 1: 2D ARRAY ON STACK MEMORY
    🔹 Q1: Create and print a 2D array using stack memory
    */
    /*
    int arr[2][4] = { 
                    {2,4,6,8},
                    {1,2,3,4}
                    };

    cout << "Printing 2D Stack Array:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    🟦 PRACTICE SET 2: 2D ARRAY ON HEAP MEMORY
    🔹 Q2: Dynamically allocate a 2D array (4x3) using new, take input, print, and deallocate
    */
    /*
    int** arr = new int*[4]; // 4 rows
    for(int i=0; i<4; i++) {
        arr[i] = new int[3]; // 3 columns
    }

    cout << "Enter 12 elements for 4x3 matrix:" << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nPrinting the 2D array from Heap:" << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    // Deallocation
    for(int i=0; i<4; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    */

    /*
    🟦 PRACTICE SET 3: 1D ARRAY ON STACK VS HEAP MEMORY
    🔹 Q3: What happens when we use stack vs heap for 1D arrays?
    */
    /*
    // Stack
    int arr[5] = {0};
    cout << "Stack array default values: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    // Heap
    int* brr =  new int[5]; // uninitialized memory
    cout << "Heap array default values (garbage): " << brr[0] << " " << brr[1] << " " << brr[2] << endl;
    delete[] brr;
    */

    /*
    🟦 PRACTICE SET 4: INTEGER ON STACK VS HEAP MEMORY
    🔹 Q4: What’s the difference between declaring an integer on the stack vs on the heap?
    */
    /*
    // Stack
    int a = 5 ;
    cout << "Integer on Stack: " << a << endl;

    // Heap
    int* p = new int;
    *p = 5;
    cout << "Integer on Heap: " << *p << endl;
    delete p;
    */

    return 0;
}
