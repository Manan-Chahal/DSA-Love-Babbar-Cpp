#include <iostream>
#include <string>
#include <algorithm>  // For sort()

using namespace std;

// Global variable to store the custom order string
string orderCopy;
// 💡 Why did we write:
// // Global variable to store the custom order string
// string orderCopy;
// ✅ Reason:
// We declared orderCopy outside the class and globally so that it can be accessed by the static comparator function cmp(), which is used inside sort().

// 🤔 But why not just pass order directly to cmp()?
// Because the comparator function used in:

// sort(s.begin(), s.end(), cmp);
// must follow this format:

// bool cmp(char a, char b);
// This function can only accept two elements being compared (in this case, characters), and can't directly accept the order string as an argument.

// Since cmp() is static, it doesn't have access to class member variables either. So to get around this, we store order in a global variable orderCopy, which the cmp() function can read.

// 🔄 How it works step-by-step:
// In customSortString(order, s), we copy the order string:

// orderCopy = order;
// Then we sort s using:

// sort(s.begin(), s.end(), cmp);
// Inside cmp(char a, char b), we use orderCopy.find(a) and orderCopy.find(b) to determine which character comes first in the custom order.

class Solution {
public:
    // Custom comparator for sorting characters
    static bool cmp(char a, char b) {
        // Compare positions of characters 'a' and 'b' in the custom order string
        // If a appears before b in 'order', return true (a should come first)
        return (orderCopy.find(a) < orderCopy.find(b));
    }

    string customSortString(string order, string s) {
        // Copy the order string to a global variable so it can be used in static comparator
        orderCopy = order;

        // Sort the string 's' using the custom comparator
        sort(s.begin(), s.end(), cmp);

        return s;
    }
};

// Driver code
int main() {
    Solution obj;

    // Example input
    string order = "cba";
    string s = "abcd";

    // Custom sort based on 'order'
    string result = obj.customSortString(order, s);

    // Output the result
    cout << "Custom sorted string: " << result << endl;

    return 0;
}

// 📝 Explanation of the Code
// What does static mean here?
// When you mark a member function (like cmp) as static, it means:

// ✅ 1. It belongs to the class, not to any specific object instance.
// You can call it without creating an object of the class.

// Example:

// cpp
// Copy
// Edit
// Solution::cmp('a', 'b');
// ✅ 2. It cannot access non-static members of the class.
// Since it doesn't belong to any object, it does not have access to this pointer, and cannot use:

// Non-static variables

// Non-static functions

// In your code:

// cpp
// Copy
// Edit
// static bool cmp(char a, char b) {
//     return orderCopy.find(a) < orderCopy.find(b);
// }
// cmp uses the global variable orderCopy, not any class member variable — because it can't access them due to being static.

// ❓Why did we make cmp() static?
// Because we are passing it as a comparator to the standard C++ sort() function:

// cpp
// Copy
// Edit
// sort(s.begin(), s.end(), cmp);
// sort() requires a normal function or a static function as a comparator.

// It cannot work with non-static member functions, because those require an object to call them.

// 🛑 If you tried to use a non-static function as a comparator, you'd get a compile error like:

// “no matching function for call to sort…”

// ✅ Summary Table:
// Aspect	Explanation
// Belongs to class?	Yes. Static functions belong to the class, not an object.
// Needs object to call?	No. You can call it like Solution::cmp('a','b').
// Can access class variables?	❌ No, unless they are also static.
// Can use global variables?	✅ Yes, like orderCopy.
// Why static in this case?	Because sort() needs a regular function or a static member as comparator.

// 💡 Alternative (Better Practice):
// To avoid static and global variables, use a lambda function inside sort():

// cpp
// Copy
// Edit
// string customSortString(string order, string s) {
//     sort(s.begin(), s.end(), [&](char a, char b) {
//         return order.find(a) < order.find(b);
//     });
//     return s;
// }
// ✅ This is cleaner, has no global variables, and works even better in modern C++.

// Let me know if you want a visual or memory model of how static functions differ!







// You said:
// But why did we use static here cant we do it without static or is itr good practice ?


// ChatGPT said:
// Excellent follow-up, Manan! Let's tackle this clearly:

// 🧠 Why did we use static here?
// cpp
// Copy
// Edit
// static bool cmp(char a, char b)
// ✅ Because we passed cmp to sort() like this:
// cpp
// Copy
// Edit
// sort(s.begin(), s.end(), cmp);
// The sort() function from the C++ Standard Library expects a comparator that is:

// Either a regular function, or

// A static class method, or

// A lambda expression

// ❌ It cannot work with non-static member functions because:

// Non-static functions require an object and have an implicit this pointer.

// sort() doesn’t know about your object, so it can’t use those functions.