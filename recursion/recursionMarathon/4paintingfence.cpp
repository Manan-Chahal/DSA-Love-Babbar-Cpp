//geeksforgeeks 

//---------- Painting Fence Algorithm ----------
/*
Problem Statement:
------------------
Count ways to paint n fence posts with k colors such that no more than 2 adjacent posts have same color.

Explanation:
------------
- For n=1: k ways (can use any color)
- For n=2: k*k ways (can use any color for both posts)
- For n>2: Need to ensure no 3+ adjacent posts have same color

Recurrence:
-----------
For each new post, we have (k-1) ways to paint it differently than previous.
If we use different color than previous, we have (previous answers) options.
*/

#include <iostream>
using namespace std;

int getPaintWays(int n, int k) {
    // Base cases
    if(n == 1) {
        return k;  // For 1 post, k different ways (one for each color)
    }
    if(n == 2) {
        return k + k*(k-1);  // For 2 posts: k ways (same color) + k*(k-1) ways (different colors)
    }

    // Recurrence: For each new post, we have (k-1) ways to paint it differently than previous
    int ans = (k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
    return ans;
}

int main() {
    // Testing painting fence algorithm
    int n = 3;  // 3 fence posts
    int k = 3;  // 3 colors
    int ans = getPaintWays(n,k);
    cout << "Ways to paint " << n << " posts with " << k << " colors: " << ans << endl;

    // Additional test cases
    cout << "Test n=1, k=2: " << getPaintWays(1,2) << " (Expected: 2)" << endl;
    cout << "Test n=2, k=2: " << getPaintWays(2,2) << " (Expected: 4)" << endl;
    cout << "Test n=3, k=2: " << getPaintWays(3,2) << " (Expected: 6)" << endl;
    cout << "Test n=4, k=3: " << getPaintWays(4,3) << " (Expected: 66)" << endl;

    return 0;
}
