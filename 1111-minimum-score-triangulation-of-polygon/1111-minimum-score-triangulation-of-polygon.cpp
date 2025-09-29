#include <vector>
#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

class Solution {
public:
    /**
     * @brief Calculates the minimum score of a triangulation of a convex polygon.
     * @param values A vector of integers representing the values of the polygon's vertices in clockwise order.
     * @return The minimum possible score.
     */
    int minScoreTriangulation(std::vector<int>& values) {
        int n = values.size();
        
        // dp[i][j] will store the minimum score to triangulate the polygon
        // with vertices from index i to j.
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // len is the number of vertices in the sub-polygon (or j - i + 1).
        // We start with triangles (len = 3) and go up to the full polygon (len = n).
        for (int len = 3; len <= n; ++len) {
            // i is the starting vertex of the sub-polygon.
            for (int i = 0; i <= n - len; ++i) {
                // j is the ending vertex of the sub-polygon.
                int j = i + len - 1;
                
                dp[i][j] = INT_MAX; // Initialize with a large value.

                // k is the pivot vertex that forms a triangle with i and j.
                // This triangle splits the polygon i...j into two smaller sub-problems.
                for (int k = i + 1; k < j; ++k) {
                    int current_score = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    dp[i][j] = std::min(dp[i][j], current_score);
                }
            }
        }

        // The result for the entire polygon (from vertex 0 to n-1).
        return dp[0][n - 1];
    }
};