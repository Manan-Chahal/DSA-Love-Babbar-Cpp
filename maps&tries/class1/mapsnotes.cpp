/*
================================================================================
                           COMPREHENSIVE GUIDE TO MAPS IN C++
================================================================================

Maps are associative containers that store elements in a mapped fashion. 
Each element has a key value and a mapped value. No two mapped values can 
have the same key values.

Types of Maps:
1. std::map - Ordered map (Red-Black Tree implementation)
2. std::unordered_map - Hash table implementation
3. std::multimap - Allows duplicate keys (ordered)
4. std::unordered_multimap - Allows duplicate keys (unordered)

================================================================================
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*
================================================================================
                                1. STD::MAP (ORDERED MAP)
================================================================================

Characteristics:
- Implemented as Red-Black Tree (self-balancing BST)
- Keys are stored in sorted order
- Search, insertion, deletion: O(log n)
- Iterating through map gives elements in sorted order of keys
- Cannot contain duplicate keys
*/

void demonstrateOrderedMap() {
    cout << "=== ORDERED MAP (std::map) DEMONSTRATION ===" << endl;
    
    // 1. DECLARATION AND INITIALIZATION
    map<int, string> studentMap;  // Empty map
    
    // Different ways to initialize
    map<int, string> grades = {{1, "A"}, {3, "B"}, {2, "C"}};
    map<string, int> wordCount{{"hello", 5}, {"world", 3}, {"cpp", 7}};
    
    // 2. INSERTION METHODS
    cout << "\n--- Insertion Methods ---" << endl;
    
    // Method 1: Using [] operator
    studentMap[101] = "Alice";
    studentMap[103] = "Bob";
    studentMap[102] = "Charlie";
    
    // Method 2: Using insert() with pair
    studentMap.insert(pair<int, string>(104, "David"));
    studentMap.insert({105, "Eve"});
    
    // Method 3: Using insert() with make_pair
    studentMap.insert(make_pair(106, "Frank"));
    
    // Method 4: Using emplace() (C++11) - constructs in-place
    studentMap.emplace(107, "Grace");
    
    cout << "Student Map after insertions:" << endl;
    for(auto& pair : studentMap) {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }
    // Note: Elements are printed in sorted order of keys (101, 102, 103, ...)
    
    // 3. ACCESS METHODS
    cout << "\n--- Access Methods ---" << endl;
    
    // Method 1: Using [] operator (creates key if doesn't exist)
    cout << "Student 102: " << studentMap[102] << endl;
    
    // Method 2: Using at() function (throws exception if key doesn't exist)
    try {
        cout << "Student 103: " << studentMap.at(103) << endl;
        cout << "Student 999: " << studentMap.at(999) << endl; // Will throw exception
    } catch(const out_of_range& e) {
        cout << "Key 999 not found!" << endl;
    }
    
    // 4. SEARCH METHODS
    cout << "\n--- Search Methods ---" << endl;
    
    // Method 1: Using find()
    auto it = studentMap.find(104);
    if(it != studentMap.end()) {
        cout << "Found student 104: " << it->second << endl;
    } else {
        cout << "Student 104 not found" << endl;
    }
    
    // Method 2: Using count() - returns 1 if exists, 0 if not (for map)
    if(studentMap.count(105)) {
        cout << "Student 105 exists: " << studentMap[105] << endl;
    }
    
    // 5. MODIFICATION
    cout << "\n--- Modification ---" << endl;
    studentMap[102] = "Charlie Brown";  // Update existing value
    cout << "Updated student 102: " << studentMap[102] << endl;
    
    // 6. DELETION
    cout << "\n--- Deletion Methods ---" << endl;
    
    // Method 1: Using erase() with key
    studentMap.erase(107);
    cout << "Erased student 107" << endl;
    
    // Method 2: Using erase() with iterator
    auto eraseIt = studentMap.find(106);
    if(eraseIt != studentMap.end()) {
        studentMap.erase(eraseIt);
        cout << "Erased student 106" << endl;
    }
    
    // Method 3: Using erase() with range
    // studentMap.erase(studentMap.begin(), studentMap.end()); // Clear all
    
    // 7. SIZE AND CAPACITY
    cout << "\n--- Size Information ---" << endl;
    cout << "Map size: " << studentMap.size() << endl;
    cout << "Is empty: " << (studentMap.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << studentMap.max_size() << endl;
    
    // 8. ITERATION METHODS
    cout << "\n--- Iteration Methods ---" << endl;
    
    // Method 1: Range-based for loop (C++11)
    cout << "Using range-based for loop:" << endl;
    for(const auto& pair : studentMap) {
        cout << pair.first << " -> " << pair.second << endl;
    }
    
    // Method 2: Iterator
    cout << "Using iterators:" << endl;
    for(auto it = studentMap.begin(); it != studentMap.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    
    // Method 3: Reverse iteration
    cout << "Reverse iteration:" << endl;
    for(auto it = studentMap.rbegin(); it != studentMap.rend(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    
    cout << endl;
}

/*
================================================================================
                            2. STD::UNORDERED_MAP (HASH MAP)
================================================================================

Characteristics:
- Implemented using Hash Table
- Keys are not stored in any particular order
- Average case: Search, insertion, deletion: O(1)
- Worst case: O(n) when many hash collisions occur
- Cannot contain duplicate keys
- Requires keys to be hashable
*/

void demonstrateUnorderedMap() {
    cout << "=== UNORDERED MAP (std::unordered_map) DEMONSTRATION ===" << endl;
    
    // 1. DECLARATION AND INITIALIZATION
    unordered_map<string, int> wordFreq;
    
    // Initialize with values
    unordered_map<char, int> charCount{{'a', 5}, {'b', 3}, {'c', 8}};
    
    // 2. INSERTION (Same methods as map)
    cout << "\n--- Insertion ---" << endl;
    wordFreq["apple"] = 10;
    wordFreq["banana"] = 7;
    wordFreq["cherry"] = 15;
    wordFreq.insert({"date", 4});
    wordFreq.emplace("elderberry", 2);
    
    cout << "Word frequencies:" << endl;
    for(const auto& pair : wordFreq) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Note: Order is not guaranteed and may vary between runs
    
    // 3. HASH TABLE SPECIFIC OPERATIONS
    cout << "\n--- Hash Table Properties ---" << endl;
    cout << "Bucket count: " << wordFreq.bucket_count() << endl;
    cout << "Load factor: " << wordFreq.load_factor() << endl;
    cout << "Max load factor: " << wordFreq.max_load_factor() << endl;
    
    // Find which bucket a key is in
    cout << "Key 'apple' is in bucket: " << wordFreq.bucket("apple") << endl;
    
    // 4. REHASHING
    cout << "\n--- Rehashing ---" << endl;
    wordFreq.rehash(20);  // Set minimum bucket count
    cout << "After rehash, bucket count: " << wordFreq.bucket_count() << endl;
    
    // 5. PERFORMANCE COMPARISON EXAMPLE
    cout << "\n--- Performance Example ---" << endl;
    
    // Counting character frequency in a string
    string text = "hello world this is a sample text for counting characters";
    unordered_map<char, int> freq;
    
    for(char c : text) {
        if(c != ' ') {  // Skip spaces
            freq[c]++;
        }
    }
    
    cout << "Character frequencies:" << endl;
    for(const auto& pair : freq) {
        cout << "'" << pair.first << "': " << pair.second << " ";
    }
    cout << endl;
}

/*
================================================================================
                           3. COMPARISON: MAP VS UNORDERED_MAP
================================================================================
*/

void compareMapTypes() {
    cout << "=== COMPARISON: MAP VS UNORDERED_MAP ===" << endl;
    
    cout << "\n| Feature              | map                | unordered_map        |" << endl;
    cout << "|---------------------|--------------------|--------------------- |" << endl;
    cout << "| Implementation      | Red-Black Tree     | Hash Table           |" << endl;
    cout << "| Time Complexity     | O(log n)           | O(1) avg, O(n) worst |" << endl;
    cout << "| Space Complexity    | O(n)               | O(n)                 |" << endl;
    cout << "| Ordering            | Sorted by key      | No specific order    |" << endl;
    cout << "| Iterator validity   | Stable             | May change on rehash |" << endl;
    cout << "| Memory overhead     | Lower              | Higher (hash table)  |" << endl;
    cout << "| Cache performance   | Better             | Worse                |" << endl;
    
    // Practical example showing the difference
    cout << "\n--- Practical Example ---" << endl;
    
    map<int, string> orderedMap;
    unordered_map<int, string> unorderedMap;
    
    // Insert same data in both
    vector<pair<int, string>> data = {{5, "five"}, {1, "one"}, {3, "three"}, {2, "two"}, {4, "four"}};
    
    for(const auto& p : data) {
        orderedMap[p.first] = p.second;
        unorderedMap[p.first] = p.second;
    }
    
    cout << "Ordered map iteration (sorted by key):" << endl;
    for(const auto& p : orderedMap) {
        cout << p.first << " ";
    }
    cout << endl;
    
    cout << "Unordered map iteration (no specific order):" << endl;
    for(const auto& p : unorderedMap) {
        cout << p.first << " ";
    }
    cout << endl;
}

/*
================================================================================
                              4. ADVANCED MAP OPERATIONS
================================================================================
*/

void advancedMapOperations() {
    cout << "=== ADVANCED MAP OPERATIONS ===" << endl;
    
    // 1. CUSTOM COMPARATOR FOR MAP
    cout << "\n--- Custom Comparator ---" << endl;
    
    // Map with custom comparator (descending order)
    map<int, string, greater<int>> descendingMap;
    descendingMap[1] = "one";
    descendingMap[5] = "five";
    descendingMap[3] = "three";
    
    cout << "Map with descending order:" << endl;
    for(const auto& p : descendingMap) {
        cout << p.first << " -> " << p.second << endl;
    }
    
    // 2. LOWER_BOUND AND UPPER_BOUND
    cout << "\n--- Lower Bound and Upper Bound ---" << endl;
    
    map<int, string> numMap = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}, {9, "nine"}};
    
    auto lower = numMap.lower_bound(4);  // First element >= 4
    auto upper = numMap.upper_bound(6);  // First element > 6
    
    cout << "Lower bound of 4: " << lower->first << " -> " << lower->second << endl;
    cout << "Upper bound of 6: " << upper->first << " -> " << upper->second << endl;
    
    // 3. EQUAL_RANGE
    auto range = numMap.equal_range(5);
    cout << "Equal range for 5: [" << range.first->first << ", " << range.second->first << ")" << endl;
    
    // 4. MAP OF MAPS (NESTED MAPS)
    cout << "\n--- Nested Maps ---" << endl;
    
    map<string, map<string, int>> studentGrades;
    studentGrades["Alice"]["Math"] = 95;
    studentGrades["Alice"]["Science"] = 87;
    studentGrades["Bob"]["Math"] = 78;
    studentGrades["Bob"]["Science"] = 92;
    
    cout << "Student grades:" << endl;
    for(const auto& student : studentGrades) {
        cout << student.first << ": ";
        for(const auto& subject : student.second) {
            cout << subject.first << "=" << subject.second << " ";
        }
        cout << endl;
    }
}

/*
================================================================================
                              5. PRACTICAL EXAMPLES
================================================================================
*/

void practicalExamples() {
    cout << "=== PRACTICAL EXAMPLES ===" << endl;
    
    // EXAMPLE 1: Word Count Program
    cout << "\n--- Example 1: Word Count ---" << endl;
    vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    unordered_map<string, int> wordCount;
    
    for(const string& word : words) {
        wordCount[word]++;
    }
    
    cout << "Word counts:" << endl;
    for(const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // EXAMPLE 2: Two Sum Problem using Hash Map
    cout << "\n--- Example 2: Two Sum Problem ---" << endl;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> numMap;  // value -> index
    
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << "\nTarget: " << target << endl;
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(numMap.find(complement) != numMap.end()) {
            cout << "Indices: " << numMap[complement] << ", " << i << endl;
            cout << "Values: " << complement << ", " << nums[i] << endl;
            break;
        }
        numMap[nums[i]] = i;
    }
    
    // EXAMPLE 3: Group Anagrams
    cout << "\n--- Example 3: Group Anagrams ---" << endl;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> anagramGroups;
    
    for(const string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());  // Sorted string as key
        anagramGroups[key].push_back(str);
    }
    
    cout << "Anagram groups:" << endl;
    for(const auto& group : anagramGroups) {
        cout << "Group: ";
        for(const string& word : group.second) {
            cout << word << " ";
        }
        cout << endl;
    }
}

/*
================================================================================
                                  6. BEST PRACTICES
================================================================================
*/

void bestPractices() {
    cout << "=== BEST PRACTICES ===" << endl;
    
    cout << "\n1. WHEN TO USE MAP VS UNORDERED_MAP:" << endl;
    cout << "   - Use map when you need sorted order or range queries" << endl;
    cout << "   - Use unordered_map for faster average lookup time" << endl;
    cout << "   - Use map for small datasets or when memory is a concern" << endl;
    
    cout << "\n2. AVOID COMMON PITFALLS:" << endl;
    cout << "   - Don't use [] operator if you're not sure key exists (creates key)" << endl;
    cout << "   - Use at() for safe access or check with find() first" << endl;
    cout << "   - Be careful with iterator invalidation in unordered_map during rehashing" << endl;
    
    cout << "\n3. PERFORMANCE TIPS:" << endl;
    cout << "   - Reserve space in unordered_map if you know approximate size" << endl;
    cout << "   - Use emplace() instead of insert() for better performance" << endl;
    cout << "   - Consider using const auto& in range-based loops to avoid copies" << endl;
    
    // Example of safe access
    cout << "\n--- Safe Access Example ---" << endl;
    unordered_map<string, int> safeMap = {{"key1", 10}, {"key2", 20}};
    
    // Bad: Creates "key3" with value 0
    // int val = safeMap["key3"];
    
    // Good: Check if key exists first
    auto it = safeMap.find("key3");
    if(it != safeMap.end()) {
        cout << "key3 value: " << it->second << endl;
    } else {
        cout << "key3 does not exist" << endl;
    }
    
    // Good: Use at() with exception handling
    try {
        int val = safeMap.at("key3");
    } catch(const out_of_range& e) {
        cout << "key3 not found using at()" << endl;
    }
}

/*
================================================================================
                                    7. MULTIMAP
================================================================================
*/

void demonstrateMultimap() {
    cout << "=== MULTIMAP DEMONSTRATION ===" << endl;
    
    // multimap allows duplicate keys
    multimap<string, int> studentScores;
    
    // Same student can have multiple scores
    studentScores.insert({"Alice", 85});
    studentScores.insert({"Alice", 92});
    studentScores.insert({"Alice", 78});
    studentScores.insert({"Bob", 90});
    studentScores.insert({"Bob", 88});
    
    cout << "Student scores (multiple scores per student):" << endl;
    for(const auto& pair : studentScores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Find all scores for a specific student
    cout << "\nAll scores for Alice:" << endl;
    auto range = studentScores.equal_range("Alice");
    for(auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
    
    // Count how many scores Alice has
    cout << "Alice has " << studentScores.count("Alice") << " scores" << endl;
}

/*
================================================================================
                              MAIN FUNCTION - RUN ALL DEMOS
================================================================================
*/

int main() {
    cout << "COMPREHENSIVE C++ MAPS TUTORIAL" << endl;
    cout << "===============================" << endl;
    
    demonstrateOrderedMap();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    demonstrateUnorderedMap();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    compareMapTypes();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    advancedMapOperations();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    practicalExamples();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    demonstrateMultimap();
    cout << "\n" << string(80, '=') << "\n" << endl;
    
    bestPractices();
    
    return 0;
}

/*
================================================================================
                                TIME COMPLEXITY SUMMARY
================================================================================

OPERATION           | MAP (ordered)    | UNORDERED_MAP (hash)
--------------------|------------------|--------------------
Insert              | O(log n)         | O(1) avg, O(n) worst
Search/Find         | O(log n)         | O(1) avg, O(n) worst
Delete              | O(log n)         | O(1) avg, O(n) worst
Iteration           | O(n)             | O(n)
Memory Usage        | Less             | More (hash table overhead)
Ordering            | Sorted by key    | No specific order
Range Queries       | Supported        | Not supported
Cache Performance   | Better           | Worse due to hashing

SPACE COMPLEXITY: Both have O(n) space complexity where n is