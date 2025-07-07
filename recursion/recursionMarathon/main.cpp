#include <iostream>
#include<vector>
using namespace std;

//---------- Count Derangements ----------
/*
Problem: Count ways to arrange n elements such that no element appears in its original position
A derangement is a permutation where no element appears in its original position.
For example, with n=3 elements [1,2,3], a derangement would be [2,3,1]
*/
int solve(int n) {
    // Base cases
    if(n == 1) {
        return 0;  // With 1 element, no derangement is possible
    }
    if(n == 2) {
        return 1;  // With 2 elements, only one derangement is possible
    }

    // Recurrence relation: D(n) = (n-1) * (D(n-1) + D(n-2))
    int ans = (n-1) * (solve(n-1) + solve(n-2));
    return ans;
}

//---------- Painting Fence Algorithm ----------
/*
Problem: Count ways to paint n fence posts with k colors such that no more than 2 adjacent posts have same color
- For n=1: k ways (can use any color)
- For n=2: k*k ways (can use any color for both posts)
- For n>2: Need to ensure no 3+ adjacent posts have same color
*/
int getPaintWays(int n, int k) {
    // Base cases
    if(n == 1) {
        return k;  // For 1 post, k different ways (one for each color)
    }
    if(n == 2) {
        return k + k*(k-1);  // For 2 posts: k ways (same color) + k*(k-1) ways (different colors)
    }

    // Recurrence: For each new post, we have (k-1) ways to paint it differently than previous
    // If we use different color than previous, we have (previous answers) options
    int ans = (k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
    return ans;
}

int main() {
    // Uncomment to test derangements
    // int n = 4;
    // cout << "Derangements for n=" << n << ": " << solve(n) << endl;

    // Testing painting fence algorithm
    int n = 3;  // 3 fence posts
    int k = 3;  // 3 colors
    int ans = getPaintWays(n,k);
    cout << "Ways to paint " << n << " posts with " << k << " colors: " << ans << endl;
    return 0;
}

//---------- House Robber 1 ----------
/*
Problem: Maximum money you can rob from houses in a line
- Adjacent houses have security systems connected
- You cannot rob adjacent houses or police will be alerted
*/
    class Solution1 {
    public:
        int solve(vector<int>& nums, int s, int e) {
            // Base case: If no houses left to rob
            if(s > e) {
                return 0;
            }
            // Option 1: Rob current house (s) and skip next house (s+1)
            int option1 = nums[s] + solve(nums, s+2, e);
            // Option 2: Skip current house, try next house
            int option2 = 0 + solve(nums, s+1, e);
            
            // Return maximum money possible
            int ans = max(option1, option2);
            return ans;
        }
        
        int rob(vector<int>& nums) {
            int n = nums.size();
            int s = 0;
            int e = n-1;
            int ans = solve(nums, s, e);
            return ans;
        }
    };

//---------- House Robber 2 ----------
/*
Problem: Same as House Robber 1, but houses are arranged in a circle
- First and last houses are now adjacent
- You need to choose between including first house (and excluding last) OR
  including last house (and excluding first)
*/
class Solution2 {
public:
    int solve(vector<int>& nums, int s, int e) {
        // Base case: If no houses left to rob
        if(s > e) {
            return 0;
        }

        // Option 1: Rob current house, skip next
        int option1 = nums[s] + solve(nums, s+2, e);
        // Option 2: Skip current house
        int option2 = 0 + solve(nums, s+1, e);

        int finalAns = max(option1, option2);
        return finalAns;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Special case: only one house
        if(n == 1) {
            return nums[0];
        }
        // Try both: exclude first house OR exclude last house
        int option1 = solve(nums, 0, n-2);  // Exclude last house
        int option2 = solve(nums, 1, n-1);  // Exclude first house

        int ans = max(option1, option2);
        return ans;
    }
};

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

//---------- Maximal Square ----------
/*
Problem: Find the area of largest square containing only 1's in a binary matrix
- Each '1' is a cell that can be part of square
- Each '0' breaks potential squares
*/
class Solution4 {
public: 
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
        // Base case: Out of bounds
        if(i >= row || j >= col) {
            return 0;
        }

        // Recursively explore all three directions to form a square
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagonal = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        // If current cell is '1', try to form a square
        if(matrix[i][j] == '1') {
            // The size of square is 1 + minimum of squares in all three directions
            int ans = 1 + min(right, min(down, diagonal));
            // Update the maximum square size found so far
            maxi = max(maxi, ans);
            return ans;
        }
        else {
            // Current cell is '0', can't form a square here
            return 0;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;  // Tracks maximum square side length
        
        // Start recursion from top-left corner
        solve(matrix, 0, 0, row, col, maxi);
        
        // Return area of largest square
        return maxi * maxi;
    }
};