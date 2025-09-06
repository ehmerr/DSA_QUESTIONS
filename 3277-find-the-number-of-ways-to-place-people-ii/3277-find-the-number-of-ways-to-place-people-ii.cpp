#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        // Step 1: Sort the points
        // Primary key: x-coordinate ascending
        // Secondary key: y-coordinate descending
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = points.size();
        int count = 0;

        // Step 2: Iterate through each point as a potential top-left corner
        for (int i = 0; i < n; ++i) {
            const auto& p_i = points[i];
            
            // Step 3: Track the "skyline" (max y-coordinate) of valid partners for p_i
            int max_y = INT_MIN; 

            // Iterate through subsequent points as potential bottom-right corners
            for (int j = i + 1; j < n; ++j) {
                const auto& p_j = points[j];

                // Condition 1: p_j must be in the "bottom-right" quadrant of p_i
                // (p_j.x >= p_i.x is guaranteed by the sort)
                if (p_j[1] <= p_i[1]) {
                    
                    // Condition 2: p_j must be "visible" (not blocked by a previous valid partner)
                    // This is true if its y-coordinate is higher than our current max_y skyline.
                    if (p_j[1] > max_y) {
                        count++;
                        // Update the skyline with this new, higher partner
                        max_y = p_j[1];
                    }
                }
            }
        }

        return count;
    }
};