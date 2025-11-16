#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max and std::min
#include <limits> // For INT_MIN and INT_MAX

class Solution {
public:
    /**
     * @brief Finds the maximum possible sum of a non-empty subarray in a circular array.
     * @param nums The circular integer array.
     * @return The maximum possible sum.
     */
    int maxSubarraySumCircular(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Initialize variables for Kadane's algorithm (both max and min)
        int totalSum = 0;
        
        int currentMax = 0;
        int globalMax = std::numeric_limits<int>::min(); // For Case 1
        
        int currentMin = 0;
        int globalMin = std::numeric_limits<int>::max(); // For Case 2

        for (int num : nums) {
            totalSum += num;

            // 1. Kadane's algorithm for maximum sum (Case 1)
            currentMax = std::max(num, currentMax + num);
            globalMax = std::max(globalMax, currentMax);

            // 2. Kadane's algorithm for minimum sum (for Case 2)
            currentMin = std::min(num, currentMin + num);
            globalMin = std::min(globalMin, currentMin);
        }

        // Calculate the maximum wrapping sum (Case 2)
        int maxWrappingSum = totalSum - globalMin;

        // Handle the edge case where all numbers are negative.
        // If globalMin == totalSum, it means the minimum subarray is the
        // entire array. In this case, maxWrappingSum (which is 0)
        // corresponds to an empty subarray, which is not allowed.
        // Therefore, we must return the globalMax (the largest negative number).
        if (globalMin == totalSum) {
            return globalMax;
        }

        // The final answer is the larger of the non-wrapping sum (globalMax)
        // and the wrapping sum (maxWrappingSum).
        return std::max(globalMax, maxWrappingSum);
    }
};