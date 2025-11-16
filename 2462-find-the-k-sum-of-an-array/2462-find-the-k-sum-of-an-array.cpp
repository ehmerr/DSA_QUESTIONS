#include <iostream>
#include <vector>
#include <numeric>     // For std::accumulate
#include <algorithm>   // For std::sort, std::abs
#include <queue>       // For std::priority_queue

class Solution {
public:
    /**
     * @brief Finds the k-th largest subsequence sum of an array.
     * @param nums The input integer array.
     * @param k A positive integer.
     * @return The k-th largest subsequence sum.
     */
    long long kSum(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0;
        std::vector<long long> abs_nums;

        // 1. Calculate max_sum (sum of all positive elements)
        //    and create the array of absolute values.
        for (int num : nums) {
            if (num > 0) {
                max_sum += num;
            }
            abs_nums.push_back(std::abs(num));
        }

        // 2. Sort the absolute values array.
        std::sort(abs_nums.begin(), abs_nums.end());

        // 3. Find the k-th smallest subsequence sum from abs_nums.
        //    pq stores {sum, next_index}
        //    We use std::greater to make it a min-heap.
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> pq;
        
        // Push the 1st smallest sum (empty set)
        pq.push({0, 0});
        
        long long k_th_smallest_sum = 0;

        // 4. Pop k times to find the k-th smallest sum.
        for (int i = 0; i < k; ++i) {
            auto [current_sum, idx] = pq.top();
            pq.pop();
            
            k_th_smallest_sum = current_sum;

            if (idx == n) {
                // We've run out of elements to add.
                continue;
            }

            // Branch 1: "Add" abs_nums[idx]
            // This represents (sum_from_before) + abs_nums[idx]
            pq.push({current_sum + abs_nums[idx], idx + 1});

            // Branch 2: "Swap" abs_nums[idx-1] with abs_nums[idx]
            // This is (sum_from_before - abs_nums[idx-1]) + abs_nums[idx]
            // This check is crucial for finding all combinations efficiently.
            if (idx > 0) {
                pq.push({current_sum - abs_nums[idx - 1] + abs_nums[idx], idx + 1});
            }
        }
        
        // 5. The final answer is max_sum - (k-th smallest sum of abs_nums).
        return max_sum - k_th_smallest_sum;
    }
};