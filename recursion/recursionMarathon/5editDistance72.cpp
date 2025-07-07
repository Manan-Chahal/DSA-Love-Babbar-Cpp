//---------- Edit Distance ----------
/*
Problem: Find minimum operations to convert string 'a' to string 'b'
- Operations allowed: Insert, Delete, Replace
- Each operation costs 1
*/
class Solution3 {
public:
    int solve(string& a, string& b, int i, int j) {
        // Base case 1: If first string is exhausted, insert remaining chars from second string
        if(i >= a.length()) {
            return b.length() - j;  // Insert all remaining characters
        }
        // Base case 2: If second string is exhausted, delete remaining chars from first string
        if(j >= b.length()) {
            return a.length() - i;  // Delete all remaining characters
        }
        
        // If characters match, no operation needed
        if(a[i] == b[j]) {
            return solve(a, b, i+1, j+1);  // Move to next characters in both strings
        }
        else {
            // Try all three operations and take minimum
            // Insert: Add a character from b to a
            int option1 = 1 + solve(a, b, i, j+1);
            // Delete: Remove current character from a
            int option2 = 1 + solve(a, b, i+1, j);
            // Replace: Change current character in a to match b
            int option3 = 1 + solve(a, b, i+1, j+1);
            
            return min(option1, min(option2, option3));
        }
    }
    
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};
