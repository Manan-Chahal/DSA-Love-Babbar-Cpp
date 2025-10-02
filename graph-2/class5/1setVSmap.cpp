/*
================================================================================
                     COMPREHENSIVE COMPARISON: SET VS MAP IN C++
================================================================================

Both set and map are associative containers in C++ STL that store elements in 
sorted order using Red-Black Tree implementation. However, they serve different 
purposes and have distinct characteristics.

Key Difference:
- SET: Stores only keys (unique values)
- MAP: Stores key-value pairs (unique keys with associated values)

================================================================================
*/

#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
================================================================================
                              1. BASIC DEFINITIONS
================================================================================
*/

void basicDefinitions() {
    cout << "=== BASIC DEFINITIONS ===" << endl;
    
    // SET: Collection of unique elements in sorted order
    set<int> mySet = {5, 2, 8, 2, 1, 9, 5};  // Duplicates automatically removed
    cout << "Set elements (sorted, unique): ";
    for(int x : mySet) {
        cout << x << " ";  // Output: 1 2 5 8 9
    }
    cout << endl;
    
    // MAP: Collection of key-value pairs, sorted by keys
    map<int, string> myMap = {{3, "three"}, {1, "one"}, {2, "two"}};
    cout << "Map elements (sorted by key): ";
    for(auto& pair : myMap) {
        cout << "[" << pair.first << ":" << pair.second << "] ";  // Output: [1:one] [2:two] [3:three]
    }
    cout << endl << endl;
}

/*
================================================================================
                           2. DETAILED COMPARISON TABLE
================================================================================
*/

void printComparisonTable() {
    cout << "=== DETAILED COMPARISON: SET VS MAP ===" << endl;
    cout << "\n| Feature              | SET                    | MAP                      |" << endl;
    cout << "|---------------------|------------------------|--------------------------|" << endl;
    cout << "| Data Structure      | Stores only keys       | Stores key-value pairs   |" << endl;
    cout << "| Element Type        | Single value           | std::pair<Key, Value>    |" << endl;
    cout << "| Uniqueness          | Unique keys only       | Unique keys only         |" << endl;
    cout << "| Ordering            | Sorted by key          | Sorted by key            |" << endl;
    cout << "| Implementation      | Red-Black Tree         | Red-Black Tree           |" << endl;
    cout << "| Time Complexity     | O(log n)               | O(log n)                 |" << endl;
    cout << "| Space Complexity    | O(n)                   | O(n)                     |" << endl;
    cout << "| Insert              | insert(value)          | insert({key, value})     |" << endl;
    cout << "| Access              | find(key) or count()   | [key] or at(key)         |" << endl;
    cout << "| Use Case            | Membership testing     | Key-value associations   |" << endl;
    cout << "| Memory Usage        | Lower                  | Higher (stores values)   |" << endl;
    cout << "| Iterator Type       | points to Key          | points to pair<Key,Val>  |" << endl;
    cout << endl;
}

/*
================================================================================
                            3. PRACTICAL EXAMPLES
================================================================================
*/

void setExamples() {
    cout << "=== SET PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Remove duplicates from array
    cout << "\n--- Example 1: Remove Duplicates ---" << endl;
    vector<int> arr = {4, 2, 7, 2, 8, 4, 1, 7, 9};
    set<int> uniqueElements(arr.begin(), arr.end());
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << "\nUnique elements: ";
    for(int x : uniqueElements) cout << x << " ";
    cout << endl;
    
    // Example 2: Check if element exists
    cout << "\n--- Example 2: Membership Testing ---" << endl;
    set<string> validUsers = {"alice", "bob", "charlie", "diana"};
    
    vector<string> loginAttempts = {"alice", "eve", "bob", "mallory"};
    for(const string& user : loginAttempts) {
        if(validUsers.count(user)) {  // or validUsers.find(user) != validUsers.end()
            cout << user << ": Valid user" << endl;
        } else {
            cout << user << ": Invalid user" << endl;
        }
    }
    
    // Example 3: Set operations
    cout << "\n--- Example 3: Set Operations ---" << endl;
    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {4, 5, 6, 7, 8};
    set<int> intersection, unionSet, difference;
    
    // Intersection
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                    inserter(intersection, intersection.begin()));
    
    // Union
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
             inserter(unionSet, unionSet.begin()));
    
    // Difference
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                  inserter(difference, difference.begin()));
    
    cout << "Set1: ";
    for(int x : set1) cout << x << " ";
    cout << "\nSet2: ";
    for(int x : set2) cout << x << " ";
    cout << "\nIntersection: ";
    for(int x : intersection) cout << x << " ";
    cout << "\nUnion: ";
    for(int x : unionSet) cout << x << " ";
    cout << "\nDifference (Set1 - Set2): ";
    for(int x : difference) cout << x << " ";
    cout << endl;
}

void mapExamples() {
    cout << "\n=== MAP PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Frequency counting
    cout << "\n--- Example 1: Character Frequency ---" << endl;
    string text = "hello world";
    map<char, int> charFreq;
    
    for(char c : text) {
        if(c != ' ') {  // Skip spaces
            charFreq[c]++;
        }
    }
    
    cout << "Character frequencies in \"" << text << "\":" << endl;
    for(auto& pair : charFreq) {
        cout << "'" << pair.first << "': " << pair.second << " ";
    }
    cout << endl;
    
    // Example 2: Student grades
    cout << "\n--- Example 2: Student Database ---" << endl;
    map<int, string> students = {
        {101, "Alice"}, {103, "Bob"}, {102, "Charlie"}, {105, "Diana"}
    };
    
    cout << "Student database (sorted by ID):" << endl;
    for(auto& pair : students) {
        cout << "ID " << pair.first << ": " << pair.second << endl;
    }
    
    // Access specific student
    int searchID = 103;
    if(students.find(searchID) != students.end()) {
        cout << "Student " << searchID << " found: " << students[searchID] << endl;
    }
    
    // Example 3: Word count in text
    cout << "\n--- Example 3: Word Count ---" << endl;
    vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    map<string, int> wordCount;
    
    for(const string& word : words) {
        wordCount[word]++;
    }
    
    cout << "Word frequencies:" << endl;
    for(auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << " times" << endl;
    }
}

/*
================================================================================
                           4. WHEN TO USE WHICH?
================================================================================
*/

void whenToUseWhich() {
    cout << "\n=== WHEN TO USE SET VS MAP ===" << endl;
    
    cout << "\nUSE SET WHEN:" << endl;
    cout << "✓ You only need to store unique values" << endl;
    cout << "✓ You want to check membership (exists/doesn't exist)" << endl;
    cout << "✓ You need set operations (union, intersection, difference)" << endl;
    cout << "✓ You want to remove duplicates from data" << endl;
    cout << "✓ You need sorted unique collection" << endl;
    cout << "✓ Memory efficiency is important" << endl;
    
    cout << "\nUSE MAP WHEN:" << endl;
    cout << "✓ You need to associate values with keys" << endl;
    cout << "✓ You want to count frequencies" << endl;
    cout << "✓ You need a lookup table or dictionary" << endl;
    cout << "✓ You want to store additional information with keys" << endl;
    cout << "✓ You need key-value relationships" << endl;
    cout << "✓ You want to implement caching or memoization" << endl;
}

/*
================================================================================
                         5. PERFORMANCE COMPARISON
================================================================================
*/

void performanceComparison() {
    cout << "\n=== PERFORMANCE COMPARISON ===" << endl;
    
    cout << "\nOPERATION COMPLEXITIES:" << endl;
    cout << "| Operation    | SET      | MAP      |" << endl;
    cout << "|-------------|----------|----------|" << endl;
    cout << "| Insert      | O(log n) | O(log n) |" << endl;
    cout << "| Search      | O(log n) | O(log n) |" << endl;
    cout << "| Delete      | O(log n) | O(log n) |" << endl;
    cout << "| Iteration   | O(n)     | O(n)     |" << endl;
    
    cout << "\nMEMORY USAGE:" << endl;
    cout << "• SET: Stores only keys (lower memory)" << endl;
    cout << "• MAP: Stores key-value pairs (higher memory)" << endl;
    cout << "• Both use Red-Black Tree with similar tree overhead" << endl;
    
    // Practical demonstration
    cout << "\n--- Memory Usage Demo ---" << endl;
    set<int> demoSet;
    map<int, string> demoMap;
    
    // Insert same keys
    for(int i = 1; i <= 5; i++) {
        demoSet.insert(i);
        demoMap[i] = "value" + to_string(i);
    }
    
    cout << "Set contains: ";
    for(int x : demoSet) cout << x << " ";
    cout << " (only keys)" << endl;
    
    cout << "Map contains: ";
    for(auto& p : demoMap) cout << "[" << p.first << ":" << p.second << "] ";
    cout << " (key-value pairs)" << endl;
}

/*
================================================================================
                     6. ADVANCED OPERATIONS COMPARISON
================================================================================
*/

void advancedOperations() {
    cout << "\n=== ADVANCED OPERATIONS ===" << endl;
    
    // Range-based operations
    cout << "\n--- Range Operations ---" << endl;
    set<int> numSet = {1, 3, 5, 7, 9, 11, 13, 15};
    map<int, string> numMap = {{1, "one"}, {3, "three"}, {5, "five"}, 
                               {7, "seven"}, {9, "nine"}, {11, "eleven"}};
    
    // Lower bound and upper bound
    cout << "Set: ";
    for(int x : numSet) cout << x << " ";
    cout << endl;
    
    auto setLower = numSet.lower_bound(6);  // First element >= 6
    auto setUpper = numSet.upper_bound(10); // First element > 10
    
    cout << "Elements in range [6, 10]: ";
    for(auto it = setLower; it != setUpper; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Map: ";
    for(auto& p : numMap) cout << "[" << p.first << ":" << p.second << "] ";
    cout << endl;
    
    auto mapLower = numMap.lower_bound(4);
    auto mapUpper = numMap.upper_bound(8);
    
    cout << "Map entries in range [4, 8]: ";
    for(auto it = mapLower; it != mapUpper; ++it) {
        cout << "[" << it->first << ":" << it->second << "] ";
    }
    cout << endl;
}

/*
================================================================================
                        7. MULTISET VS MULTIMAP
================================================================================
*/

void multiContainers() {
    cout << "\n=== MULTISET VS MULTIMAP ===" << endl;
    
    cout << "\nMULTISET (allows duplicate keys):" << endl;
    multiset<int> mset = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    cout << "Multiset: ";
    for(int x : mset) cout << x << " ";
    cout << "\nCount of 1: " << mset.count(1) << endl;
    cout << "Count of 5: " << mset.count(5) << endl;
    
    cout << "\nMULTIMAP (allows duplicate keys):" << endl;
    multimap<string, int> mmap;
    mmap.insert({"student", 85});
    mmap.insert({"student", 92});
    mmap.insert({"student", 78});
    mmap.insert({"teacher", 95});
    
    cout << "Multimap entries:" << endl;
    for(auto& p : mmap) {
        cout << p.first << ": " << p.second << endl;
    }
    
    cout << "All scores for 'student': ";
    auto range = mmap.equal_range("student");
    for(auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}

/*
================================================================================
                           8. UNORDERED VARIANTS
================================================================================
*/

void unorderedVariants() {
    cout << "\n=== UNORDERED VARIANTS ===" << endl;
    
    cout << "\nCOMPARISON WITH UNORDERED VARIANTS:" << endl;
    cout << "| Container      | Ordering | Time Complexity | Implementation |" << endl;
    cout << "|---------------|----------|-----------------|----------------|" << endl;
    cout << "| set           | Sorted   | O(log n)        | Red-Black Tree |" << endl;
    cout << "| unordered_set | None     | O(1) avg        | Hash Table     |" << endl;
    cout << "| map           | Sorted   | O(log n)        | Red-Black Tree |" << endl;
    cout << "| unordered_map | None     | O(1) avg        | Hash Table     |" << endl;
    
    // Practical demonstration
    cout << "\n--- Ordering Demonstration ---" << endl;
    vector<int> data = {5, 2, 8, 1, 9, 3};
    
    set<int> orderedSet(data.begin(), data.end());
    unordered_set<int> unorderedSet(data.begin(), data.end());
    
    cout << "Original data: ";
    for(int x : data) cout << x << " ";
    cout << endl;
    
    cout << "set (ordered): ";
    for(int x : orderedSet) cout << x << " ";
    cout << endl;
    
    cout << "unordered_set: ";
    for(int x : unorderedSet) cout << x << " ";
    cout << " (no guaranteed order)" << endl;
}

/*
================================================================================
                              9. REAL WORLD EXAMPLES
================================================================================
*/

void realWorldExamples() {
    cout << "\n=== REAL WORLD APPLICATIONS ===" << endl;
    
    // SET Applications
    cout << "\n--- SET Applications ---" << endl;
    cout << "1. User Permissions System:" << endl;
    set<string> adminPermissions = {"read", "write", "delete", "execute"};
    set<string> userPermissions = {"read", "write"};
    
    string action = "delete";
    if(adminPermissions.count(action)) {
        cout << "   Admin can " << action << endl;
    }
    if(userPermissions.count(action)) {
        cout << "   User can " << action << endl;
    } else {
        cout << "   User cannot " << action << endl;
    }
    
    // MAP Applications
    cout << "\n2. Configuration Management:" << endl;
    map<string, string> config = {
        {"server_host", "localhost"},
        {"server_port", "8080"},
        {"database_url", "mysql://localhost:3306"},
        {"max_connections", "100"}
    };
    
    cout << "   Configuration settings:" << endl;
    for(auto& setting : config) {
        cout << "   " << setting.first << " = " << setting.second << endl;
    }
    
    cout << "\n3. Grade Book System:" << endl;
    map<string, map<string, int>> gradebook = {
        {"Alice", {{"Math", 95}, {"Science", 87}, {"English", 92}}},
        {"Bob", {{"Math", 78}, {"Science", 92}, {"English", 85}}}
    };
    
    for(auto& student : gradebook) {
        cout << "   " << student.first << "'s grades: ";
        for(auto& subject : student.second) {
            cout << subject.first << "=" << subject.second << " ";
        }
        cout << endl;
    }
}

/*
================================================================================
                                MAIN FUNCTION
================================================================================
*/

int main() {
    cout << "COMPREHENSIVE C++ SET VS MAP COMPARISON" << endl;
    cout << "=======================================" << endl;
    
    basicDefinitions();
    cout << string(80, '-') << endl;
    
    printComparisonTable();
    cout << string(80, '-') << endl;
    
    setExamples();
    cout << string(80, '-') << endl;
    
    mapExamples();
    cout << string(80, '-') << endl;
    
    whenToUseWhich();
    cout << string(80, '-') << endl;
    
    performanceComparison();
    cout << string(80, '-') << endl;
    
    advancedOperations();
    cout << string(80, '-') << endl;
    
    multiContainers();
    cout << string(80, '-') << endl;
    
    unorderedVariants();
    cout << string(80, '-') << endl;
    
    realWorldExamples();
    
    return 0;
}

/*
================================================================================
                              SUMMARY & KEY TAKEAWAYS
================================================================================

QUICK DECISION GUIDE:

Choose SET when you need:
• Unique collection of values
• Fast membership testing
• Set operations (union, intersection)
• Remove duplicates
• Sorted unique elements

Choose MAP when you need:
• Key-value associations
• Lookup tables/dictionaries
• Frequency counting
• Configuration storage
• Caching/memoization

MEMORY CONSIDERATIONS:
• SET: Stores only keys (more memory efficient)
• MAP: Stores key-value pairs (higher memory usage)

PERFORMANCE:
• Both have O(log n) operations
• Both use Red-Black Tree implementation
• Both maintain sorted order
• Consider unordered variants for O(1) average performance

COMMON PITFALLS:
• Don't use map when you only need membership testing
• Don't use set when you need to associate additional data
• Remember that both store unique keys only
• Consider multiset/multimap for duplicate keys

================================================================================
*/