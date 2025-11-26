#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        
        // dp[i][j][rem]
        // Using vector for dynamic sizing based on grid dimensions
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        // Base Case: The starting cell
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the starting cell (already initialized)
                if (i == 0 && j == 0) continue;
                
                int val = grid[i][j];
                
                // Iterate through all possible remainders (0 to k-1)
                for (int rem = 0; rem < k; ++rem) {
                    // The new remainder after adding the current cell's value
                    int next_rem = (rem + val) % k;
                    
                    // Add paths from Top (i-1, j)
                    if (i > 0) {
                        dp[i][j][next_rem] = (dp[i][j][next_rem] + dp[i-1][j][rem]) % MOD;
                    }
                    
                    // Add paths from Left (i, j-1)
                    if (j > 0) {
                        dp[i][j][next_rem] = (dp[i][j][next_rem] + dp[i][j-1][rem]) % MOD;
                    }
                }
            }
        }
        
        // Return paths reaching bottom-right with remainder 0
        return dp[m-1][n-1][0];
    }
};