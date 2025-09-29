#include <vector>
#include <numeric>   // For std::accumulate, std::partial_sum
#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        
        // 1. Check if merging is possible.
        // Each merge reduces the number of piles by K-1.
        // To go from n piles to 1, we need n-1 total reduction.
        if ((n - 1) % (K - 1) != 0) {
            return -1;
        }

        // 2. Create a prefix sum array for efficient range sum queries.
        // prefixSum[i] stores the sum of stones[0]...stones[i-1].
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }

        // 3. Initialize DP table.
        // dp[i][j] = min cost to merge stones[i...j] into one pile.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 4. Fill the DP table.
        // len is the length of the subarray we are considering.
        for (int len = K; len <= n; ++len) {
            // i is the starting index of the subarray.
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // p is the split point. We merge [i..p] and [p+1..j] separately.
                // The crucial optimization is that the left part [i..p] must be
                // reducible to one pile, so we can step p by K-1.
                for (int p = i; p < j; p += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
                }

                // If the current range [i..j] can be merged into a single pile,
                // add the cost of that final merge operation.
                if ((j - i) % (K - 1) == 0) {
                    dp[i][j] += prefixSum[j + 1] - prefixSum[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};