#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // Pointer to write compressed characters
        int i = 0;     // Pointer to read/traverse the chars

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Step 1: Count how many times currentChar appears consecutively
            while (i < n && chars[i] == currentChar) {
                i++;     // move forward
                count++; // count frequency
            }

            // Step 2: Write the character once
            chars[write++] = currentChar;

            // Step 3: If count > 1, write its digits (e.g., '12' => '1' and '2')
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[write++] = ch; // write each digit separately
                }
            }
        }

        // Step 4: Return the new length of the compressed array
        return write;
    }
};
int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}; // Example input

    int newLength = solution.compress(chars);

    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}