#include <iostream>
#include <string>
using namespace std;

// Function to reverse the string using recursion and swap
void reverseString(string &s, int start, int end) {
    // Base case: when the pointers meet or cross
    if (start >= end)
        return;

    // Swap characters at start and end
    swap(s[start], s[end]);

    // Recursive call for the remaining substring
    reverseString(s, start + 1, end - 1);
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Call the recursive function
    reverseString(str, 0, str.length() - 1);

    cout << "Reversed string: " << str << endl;

    return 0;
}
