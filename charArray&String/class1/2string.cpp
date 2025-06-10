#include <iostream>
#include <string>  /* For std::string */
using namespace std;

int main() {

    /* 
    Comparing two strings s1 and s2 using the compare() function.
    compare() returns:
    - 0 if both strings are equal,
    - negative value if s1 is lexicographically less than s2,
    - positive value if s1 is lexicographically greater than s2.
    */
    string s1 = "love";
    string s2 = "amit";
    cout << "Comparison of \"" << s1 << "\" and \"" << s2 << "\": " << s1.compare(s2) << endl;

    /* 
    Find substring example:
    We want to find if a word exists inside a larger string.
    The find() method returns the starting index if found, else string::npos.
    */
    string name = "Hello Jee Kaise ho Saare";
    string word = "Kaise ho";

    if(name.find(word) != string::npos) {
        cout << "\"" << word << "\" found in \"" << name << "\" at index " << name.find(word) << endl;
    } else {
        cout << "\"" << word << "\" not found in \"" << name << "\"" << endl;
    }

    /* 
    Substring extraction:
    substr(pos) extracts substring from position 'pos' till the end.
    substr(pos, len) extracts substring starting at 'pos' of length 'len'.
    */
    cout << "Substring from index 5: " << name.substr(5) << endl;
    cout << "Substring from index 5 of length 5: " << name.substr(5, 5) << endl;

    /*
    String concatenation:
    The + operator joins two strings.
    Here, we add a space in between for formatting.
    */
    string fName = "Love";
    string lName = "babbar";
    string fullName = fName + " " + lName;
    cout << "Full name: " << fullName << endl;

    /*
    Checking if a string is empty:
    clear() empties the string content.
    empty() returns true if string length is zero.
    */
    string someName = "Maharana Pratap";
    someName.clear();

    if(someName.empty()) {
        cout << "String is empty" << endl;
    } else {
        cout << "String is not empty" << endl;
    }

    /*
    Iterating over a string using an iterator:
    begin() returns iterator to first character,
    end() returns iterator past the last character.
    */
    string iterateName = "Maharana Pratap";
    auto it = iterateName.begin();
    cout << "Characters in string: ";
    while(it != iterateName.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    /*
    Accessing characters in a string:
    - Using [] operator or at() method (at() throws out_of_range exception if invalid).
    - front() returns first character.
    - back() returns last character.
    - length() returns number of characters.
    */
    cout << "First character (using []): " << iterateName[0] << endl;
    cout << "First character (using at()): " << iterateName.at(0) << endl;
    cout << "First character (front()): " << iterateName.front() << endl;
    cout << "Last character (back()): " << iterateName.back() << endl;
    cout << "Length of string: " << iterateName.length() << endl;

    /*
    Reading a full line from input (including spaces):
    getline(cin, str, '\n') reads until newline.
    */
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence, '\n');
    cout << "You entered: " << sentence << endl;

    /*
    Push and pop characters in string:
    - push_back() adds character at end.
    - pop_back() removes last character.
    */
    string str;
    str.push_back('l');
    str.push_back('o');
    str.push_back('v');
    str.push_back('e');

    cout << "String after pushes: " << str << endl;

    str.pop_back();
    cout << "String after pop_back: " << str << endl;

    /*
    Input a word (no spaces):
    cin >> str reads until first whitespace.
    */
    cout << "Enter a word: ";
    cin >> str;
    cout << "You entered: " << str << endl;
    cout << "First character: " << str[0] << endl;

    return 0;
}
