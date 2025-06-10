#include <iostream>
#include <cstring>  // For C-string functions like strlen, strcpy
#include <string>   // For std::string

using namespace std;

int main() {

    // 1. Basic Definition and Usage
    // Char array: fixed-size, null-terminated character array (C-style string)
    char charArr[] = "hello";

    // std::string: dynamic, high-level string class
    string str = "hello";

    cout << "Char array: " << charArr << endl;
    cout << "std::string: " << str << endl;

    // 2. Memory Management
    // Char array requires manual sizing and care to avoid overflow
    char buffer[10]; 
    strcpy(buffer, "hi");  // Safe because buffer is large enough

    // std::string manages memory automatically
    str = "hello world! this string can grow dynamically";

    cout << "Char buffer: " << buffer << endl;
    cout << "Dynamic std::string: " << str << endl;

    // 3. Functions and Operations
    // Char arrays use C functions (from <cstring>)
    cout << "Length of charArr using strlen: " << strlen(charArr) << endl;

    // std::string offers intuitive member functions
    str += " More text."; // Appending with operator+=
    cout << "Appended std::string: " << str << endl;

    // 4. Safety and Convenience
    // Char arrays are prone to buffer overflow and require manual management
    // Example: no built-in safety for strcpy if buffer too small (not shown here to avoid crash)
    // std::string handles memory safely and throws exceptions on some errors

    // 5. Performance
    // Char arrays can be faster when size is fixed and known at compile time
    // std::string trades slight overhead for safety and ease of use (no code here, theoretical)

    // 6. Interoperability with C Functions
    // Char array can be directly passed to C functions
    cout << "Char array passed to printf: ";
    printf("%s\n", charArr);

    // std::string can be converted to const char* using c_str()
    const char* cstr = str.c_str();
    cout << "std::string converted to C string: " << cstr << endl;

    // 7. Best Practices (comments only)
    // Use char arrays mainly when:
    // - Interfacing with legacy C APIs
    // - Working in constrained environments with strict memory limits
    //
    // Use std::string in most other cases for safety, ease, and functionality

    return 0;
}
