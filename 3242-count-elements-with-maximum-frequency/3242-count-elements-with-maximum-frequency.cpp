#include <vector>
#include <numeric> // For std::accumulate if needed, though not used here.

class Solution {
public:
    /**
     * @brief Counts the total number of elements that have the maximum frequency.
     * @param nums A vector of integers.
     * @return The total count of elements with the highest frequency.
     */
    int maxFrequencyElements(std::vector<int>& nums) {
        // Step 1: Count the frequency of each element.
        // Constraints are 1 <= nums[i] <= 1000, so a vector is efficient.
        std::vector<int> freq(1001, 0);
        for (int num : nums) {
            freq[num]++;
        }

        int max_freq = 0;
        int total_count = 0;

        // Step 2: Find the max frequency and sum counts of elements with that frequency.
        for (int f : freq) {
            // If f is 0, it means the number was not in the input, so we skip it.
            if (f == 0) {
                continue;
            }

            if (f > max_freq) {
                // Found a new highest frequency.
                max_freq = f;
                // Reset the total count to this new frequency.
                total_count = f;
            } else if (f == max_freq) {
                // Found another element with the same max frequency.
                // Add its frequency to the total count.
                total_count += f;
            }
        }

        return total_count;
    }
};