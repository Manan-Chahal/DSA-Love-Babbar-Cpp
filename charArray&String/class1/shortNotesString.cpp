#include <iostream>
#include <string>     // std::string
#include <algorithm>  // std::transform, std::find
#include <cctype>     // toupper, tolower
#include <sstream>    // std::stringstream
#include <vector>
using namespace std;

/*
======================
| C++ std::string Guide |
======================
This guide covers:
1. Creation & initialization
2. Input/output methods
3. Size & capacity
4. Access & iteration
5. Modifiers (append, insert, erase, replace)
6. Substring & find
7. Comparison operators
8. Convert to/from numbers
9. Case conversion
10. Split & join
11. Other utilities (swap, clear, reserve, shrink_to_fit)
*/

// 1️⃣ Creation & Initialization
void demoCreation() {
    string s1;                        // Empty
    string s2 = "Hello";             // Literal
    string s3("World");              // Constructor
    string s4 = s2;                  // Copy constructor
    string s5(5, '!');               // '!!!!!'
    cout << s1 << "|" << s2 << "|" << s3 << "|" << s4 << "|" << s5 << "\n";
}

// 2️⃣ Input / Output
void demoIO() {
    string str;
    cout << "Enter a word: ";       // no spaces
    cin >> str;
    cout << "You entered: " << str << "\n";

    cin.ignore();                   // flush newline
    cout << "Enter a full line: ";
    getline(cin, str);             // with spaces
    cout << "Line: " << str << "\n";
}

// 3️⃣ Size & Capacity
void demoSizeCapacity() {
    string s = "Example";
    cout << "Size: " << s.size()
         << ", Length: " << s.length()
         << ", Capacity: " << s.capacity() << "\n";
    cout << "Empty? " << boolalpha << s.empty() << "\n";
}

// 4️⃣ Access & Iteration
void demoAccess() {
    string s = "Access";
    cout << s[0] << " " << s.at(1) << " " << s.front() << " " << s.back() << "\n";
    cout << "Chars: ";
    for (char c : s) cout << c << ' ';
    cout << "\nIter backward: ";
    for (auto it = s.rbegin(); it != s.rend(); ++it) cout << *it;
    cout << "\n";
}

// 5️⃣ Modifiers
void demoModifiers() {
    string s = "Mod";
    s += "ify";                     // append literal
    s.append(3, '!');              // "Modify!!!"
    s.insert(0, "X-");             // "X-Modify!!!"
    s.erase(0, 2);                 // removes "X-"
    s.replace(3, 4, "TEST");       // replace "ify!" part
    cout << "Modified string: " << s << "\n";
}

// 6️⃣ Substring & Find
void demoSubFind() {
    string s = "Find substring in this example";
    auto pos = s.find("substr");
    if (pos != string::npos) {
        cout << "Found at " << pos
             << ", substring: " << s.substr(pos, 9) << "\n";
    }
    cout << "Last 'e' at " << s.find_last_of('e') << "\n";
}

// 7️⃣ Comparisons
void demoComparisons() {
    string a = "abc", b = "abd";
    cout << boolalpha;
    cout << (a < b) << " " << a.compare(b) << " " << (a == b) << "\n";
}

// 8️⃣ Convert to/from numbers
void demoConversions() {
    int n = 123;
    double d = 45.6;
    string sn = to_string(n);
    string sd = to_string(d);
    cout << sn << " " << sd << "\n";
    int n2 = stoi(sn);
    double d2 = stod(sd);
    cout << n2 << " " << d2 << " (types restored)\n";
}

// 9️⃣ Case conversion
void demoCaseConversion() {
    string s = "AbCdE";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << "Lower: " << s << "\n";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "Upper: " << s << "\n";
}

// 🔟 Split & Join (using stringstream)
vector<string> split(const string &s, char delim) {
    vector<string> tokens;
    string tok;
    stringstream ss(s);
    while (getline(ss, tok, delim)) tokens.push_back(tok);
    return tokens;
}

string demoJoin(const vector<string> &parts, char delim) {
    string out;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i) out += delim;
        out += parts[i];
    }
    return out;
}

void demoSplitJoin() {
    string s = "a,b,c,d";
    auto parts = split(s, ',');
    cout << "Split into: ";
    for (auto &p : parts) cout << "[" << p << "]";
    cout << "\nJoin back: " << demoJoin(parts, '*') << "\n";
}

// 1⃣1⃣ Other utilities
void demoUtilities() {
    string s1 = "short";
    string s2 = "This is longer";
    s1.swap(s2);
    cout << "After swap: " << s1 << " | " << s2 << "\n";
    s1.clear();
    cout << "Cleared s1? " << s1.empty() << "\n";
    s2.reserve(50);
    cout << "Reserved cap: " << s2.capacity() << "\n";
    s2.shrink_to_fit();
    cout << "Shrunk cap: " << s2.capacity() << "\n";
}

int main() {
    demoCreation();      cout << "--------------\n";
    demoIO();            cout << "--------------\n";
    demoSizeCapacity();  cout << "--------------\n";
    demoAccess();        cout << "--------------\n";
    demoModifiers();     cout << "--------------\n";
    demoSubFind();       cout << "--------------\n";
    demoComparisons();   cout << "--------------\n";
    demoConversions();   cout << "--------------\n";
    demoCaseConversion();cout << "--------------\n";
    demoSplitJoin();     cout << "--------------\n";
    demoUtilities();     cout << "--------------\n";
    return 0;
}
