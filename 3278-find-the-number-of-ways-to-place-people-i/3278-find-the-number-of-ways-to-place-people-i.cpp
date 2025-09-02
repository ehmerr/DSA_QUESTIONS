#include <vector>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        int n = points.size();
        int valid_pairs_count = 0;

        // Iterate through every possible ordered pair of points (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // A point cannot form a pair with itself
                if (i == j) {
                    continue;
                }

                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];

                // 1. Check the positional rule: i must be top-left of j
                if (xi <= xj && yi >= yj) {
                    
                    // This is a potential pair. Now, check the emptiness rule.
                    bool is_valid_pair = true;
                    
                    // 2. Iterate through all other points 'k' to check if any are inside the rectangle
                    for (int k = 0; k < n; ++k) {
                        // Don't check the points forming the rectangle's corners
                        if (k == i || k == j) {
                            continue;
                        }

                        int xk = points[k][0];
                        int yk = points[k][1];
                        
                        // Check if point k is inside the bounding box defined by i and j
                        if (xk >= xi && xk <= xj && yk >= yj && yk <= yi) {
                            // Found a point inside, so this pair (i, j) is not valid
                            is_valid_pair = false;
                            break; // No need to check other k's for this pair
                        }
                    }

                    // If the inner loop finished without finding any interfering points
                    if (is_valid_pair) {
                        valid_pairs_count++;
                    }
                }
            }
        }
        
        return valid_pairs_count;
    }
};