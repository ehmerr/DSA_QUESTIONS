#include <vector>
#include <string>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] will store the maximum number of strings we can form
        // using at most 'i' zeroes and 'j' ones.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Iterate through each string in the input list
        for (const string& s : strs) {
            
            // 1. Count the zeroes and ones for the current string
            int zeros = 0;
            int ones = 0;
            for (char c : s) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }

            // 2. Update the DP table (0/1 Knapsack logic)
            // We iterate backward to avoid using the same string multiple times
            // for a single state.
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    // We have two choices:
                    //   a) Don't include the current string 's'.
                    //      The count remains dp[i][j] (from the previous iteration).
                    //   b) Include the current string 's'.
                    //      The count is 1 (for this string) + the best we could do
                    //      with the remaining capacity (dp[i - zeros][j - ones]).
                    
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        // The final answer is the max strings we can form with the
        // full capacity of 'm' zeroes and 'n' ones.
        return dp[m][n];
    }
};