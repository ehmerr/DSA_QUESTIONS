#include <vector>
#include <numeric> // For std::gcd
#include <algorithm> // For std::min
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;

        // 1. Check for Case 1: Array already contains 1s
        for (int val : nums) {
            if (val == 1) {
                onesCount++;
            }
        }

        if (onesCount > 0) {
            return n - onesCount;
        }

        // 2. Check for Case 2: No 1s exist.
        // We must find the shortest subarray with gcd == 1.
        int min_k = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int current_gcd = nums[i];
            
            // "Grow" the subarray starting from i
            for (int j = i + 1; j < n; ++j) {
                current_gcd = std::gcd(current_gcd, nums[j]);
                
                if (current_gcd == 1) {
                    // We found a subarray nums[i...j] with gcd == 1
                    int k = (j - i) + 1; // Length of this subarray
                    min_k = std::min(min_k, k);
                    break; // No need to check longer subarrays starting from i
                }
            }
        }

        // 3. Check for Impossibility
        if (min_k == INT_MAX) {
            // No subarray, not even the full array, has gcd == 1.
            return -1;
        }

        // 4. Calculate total operations
        // (k - 1) ops to create the first '1'
        // (n - 1) ops to spread that '1' to all other n-1 elements
        return (min_k - 1) + (n - 1);
    }
};