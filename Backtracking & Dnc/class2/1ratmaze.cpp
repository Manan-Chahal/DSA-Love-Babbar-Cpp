
//geeksforgeeks

//---------- Rat in a Maze (Backtracking) ----------
// Problem: Find all possible paths for a rat to go from (0,0) to (n-1,n-1) in a grid.
// The rat can move Up, Down, Left, Right, but only through open cells (1) and cannot visit any cell more than once in a path.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Helper function to check if the next move is valid
    bool isSafe(int newx, int newy, vector<vector<int>> &m, vector<vector<bool>> &visited, int n ) {
        // Check if new coordinates are within bounds
        if(newx < 0 || newy < 0 || newx >= n || newy >= n ) {
            return false;
        }
        // Check if cell is already visited in current path
        if(visited[newx][newy] == true) {
            return false;
        }
        // Check if cell is blocked (0)
        if(m[newx][newy] == 0) {
            return false;
        }
        // Valid move
        return true;
    }
    
    // Recursive function to explore all paths using backtracking
    void solve(vector<vector<int>> &m, vector<vector<bool>> &visited, int n, vector<string> &ans,
                int curr_x, int curr_y, int destx, int desty, string output) {
        // Base case: If rat reaches destination, store the path
        if(curr_x == destx && curr_y == desty) {
            ans.push_back(output);
            return;
        }
        
        // Arrays for movement in 4 directions: Up, Down, Left, Right
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        char move[] = {'U','D','L','R'};
        
        // Try all 4 directions
        for(int i=0; i<4; i++) {
            int newx = curr_x + dx[i];
            int newy = curr_y + dy[i];
            char movement = move[i];
            
            // If move is safe, mark visited, add move to path, and recurse
            if(isSafe(newx, newy, m, visited, n)) {
                visited[newx][newy] = true;
                output.push_back(movement);
                solve(m, visited, n, ans, newx, newy, destx, desty, output);
                // Backtrack: remove last move and unmark visited
                output.pop_back();
                visited[newx][newy] = false;
            }
        }
        // The commented code below shows how you could write each direction separately,
        // but the loop above is more concise and avoids repetition.
    }

    // Main function to find all paths from (0,0) to (n-1,n-1)
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans; // Stores all valid paths
        vector<vector<bool>> visited(n, vector<bool>(n,0)); // Visited matrix for backtracking
        int curr_x = 0;
        int curr_y = 0;
        visited[0][0] = true; // Start position is visited
        int destx = n-1;
        int desty = n-1;
        string output = ""; // To build the path string
        
        // If start cell is blocked, return no paths
        if(m[0][0] == 0) {
            return ans;
        }
        
        // Start recursive exploration
        solve(m, visited, n, ans, curr_x, curr_y, destx, desty, output);
        
        return ans;
    }
};

// Driver code to test the solution
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

/*
EXPLANATION OF THE CODE:
------------------------
- isSafe: Checks if the next cell is within bounds, not visited, and open (1).
- solve: Recursively explores all four directions from the current cell. If a move is valid, it marks the cell as visited, adds the move to the path, and recurses. After recursion, it backtracks by unmarking the cell and removing the move from the path.
- findPath: Initializes visited matrix, checks if the start is open, and starts the recursive search.
- main: Handles multiple test cases, reads the matrix, and prints all valid paths in lexicographical order.

TIME COMPLEXITY:
----------------
- In the worst case (all open cells), the number of paths can be exponential (O(4^(n*n))), since from each cell, you can try up to 4 directions.
- Pruning (blocked/visited cells) reduces actual work.

SPACE COMPLEXITY:
-----------------
- O(n*n) for the visited matrix and recursion
*/