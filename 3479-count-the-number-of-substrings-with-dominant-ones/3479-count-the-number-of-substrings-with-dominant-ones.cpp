#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int n = s.length();
        long long ans = 0;

        // --- 1. Handle n0 = 0 (all '1's) case ---
        // This counts all substrings made of only '1's.
        long long current_ones = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                current_ones++;
            } else {
                // End of a '1' block
                ans += current_ones * (current_ones + 1) / 2;
                current_ones = 0;
            }
        }
        // Add the last block of '1's (if any)
        ans += current_ones * (current_ones + 1) / 2;

        // --- 2. Handle n0 >= 1 cases ---
        
        // Find max k (n0) to check: k^2 + k <= n
        int k_max = (int)((-1.0 + std::sqrt(1.0 + 4.0 * n)) / 2.0);

        // Get indices of all zeros, with sentinels at start/end
        std::vector<int> zero_indices;
        zero_indices.push_back(-1); // Sentinel for left boundary
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zero_indices.push_back(i);
            }
        }
        zero_indices.push_back(n); // Sentinel for right boundary

        int num_zeros = zero_indices.size() - 2;
        if (num_zeros == 0) {
            return (int)ans; // String was all '1's
        }

        // Iterate for each possible number of zeros k
        for (int k = 1; k <= k_max && k <= num_zeros; ++k) {
            long long required_ones_total = (long long)k * k;
            
            // Iterate through all windows of k zeros
            // p points to the *first* zero in the window
            for (int p = 1; p + k - 1 <= num_zeros; ++p) {
                int first_zero_p = p;
                int last_zero_p = p + k - 1;

                // Get the actual string indices of the zeros
                int first_zero_idx = zero_indices[first_zero_p];
                int last_zero_idx = zero_indices[last_zero_p];

                // Get the boundaries (the '0' *before* the window and *after*)
                int left_boundary_idx = zero_indices[first_zero_p - 1];
                int right_boundary_idx = zero_indices[last_zero_p + 1];

                // Calculate '1's *between* the first and last zero
                int n1_mid = (last_zero_idx - first_zero_idx + 1) - k;

                // Ones we need to add from the left/right
                long long required_ones_outer = required_ones_total - n1_mid;

                // Max '1's we *can* add from left/right
                int max_n1_left = first_zero_idx - left_boundary_idx - 1;
                int max_n1_right = right_boundary_idx - last_zero_idx - 1;

                // If we can't possibly add enough ones, skip
                if (required_ones_outer > max_n1_left + max_n1_right) {
                    continue;
                }

                // Now, count pairs (n1_l, n1_r)
                // 0 <= n1_l <= max_n1_left
                // 0 <= n1_r <= max_n1_right
                // n1_l + n1_r >= required_ones_outer
                
                // We iterate n1_l from 0 to max_n1_left
                // For each n1_l, we need:
                // n1_r >= required_ones_outer - n1_l
                // We also need n1_r <= max_n1_right
                // So, we need: max(0, req - n1_l) <= n1_r <= max_n1_right
                
                for (int n1_l = 0; n1_l <= max_n1_left; ++n1_l) {
                    long long min_n1_r = std::max(0LL, required_ones_outer - n1_l);
                    
                    if (min_n1_r <= max_n1_right) {
                        // The number of valid n1_r values is:
                        // (max_n1_right - min_n1_r + 1)
                        ans += (max_n1_right - min_n1_r + 1);
                    }
                }
            }
        }
        
        return (int)ans;
    }
};