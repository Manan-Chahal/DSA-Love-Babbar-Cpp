#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> subtreeXor;
    std::vector<int> startTime, endTime;
    int timer;

    // DFS to pre-compute subtree XOR sums and DFS start/end times
    void dfs(int u, int p, const std::vector<int>& nums) {
        startTime[u] = timer++;
        subtreeXor[u] = nums[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, nums);
            subtreeXor[u] ^= subtreeXor[v];
        }
        endTime[u] = timer++;
    }

    // Checks if node u is an ancestor of node v
    bool isAncestor(int u, int v) {
        return startTime[u] <= startTime[v] && endTime[u] >= endTime[v];
    }

public:
    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        adj.assign(n, std::vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        subtreeXor.assign(n, 0);
        startTime.assign(n, 0);
        endTime.assign(n, 0);
        timer = 0;

        // 1. Pre-computation from root 0
        dfs(0, -1, nums);

        int totalXor = subtreeXor[0];
        int minScore = INT_MAX;

        // 2. Iterate through all pairs of edges to cut.
        // An edge cut is represented by its child node (i or j).
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xor1, xor2, xor3;

                // Determine the relationship between the subtrees of i and j
                if (isAncestor(i, j)) { // Case 1: j's subtree is inside i's subtree
                    xor1 = subtreeXor[j];
                    xor2 = subtreeXor[i] ^ subtreeXor[j];
                    xor3 = totalXor ^ subtreeXor[i];
                } else if (isAncestor(j, i)) { // Case 1: i's subtree is inside j's subtree
                    xor1 = subtreeXor[i];
                    xor2 = subtreeXor[j] ^ subtreeXor[i];
                    xor3 = totalXor ^ subtreeXor[j];
                } else { // Case 2: Disjoint subtrees
                    xor1 = subtreeXor[i];
                    xor2 = subtreeXor[j];
                    xor3 = totalXor ^ subtreeXor[i] ^ subtreeXor[j];
                }

                // 3. Calculate and update the minimum score
                int score = std::max({xor1, xor2, xor3}) - std::min({xor1, xor2, xor3});
                minScore = std::min(minScore, score);
            }
        }

        return minScore;
    }
};