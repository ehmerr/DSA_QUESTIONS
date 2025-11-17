#include <vector>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        // Initialize count to k. This cleverly handles the first '1'
        // encountered, as the check (k < k) will be false.
        int count = k; 
        
        for (int num : nums) {
            if (num == 1) {
                // If we find a '1', check if the count of zeros
                // since the last '1' is less than k.
                if (count < k) {
                    // We found a '1' that is too close to the previous one.
                    return false;
                }
                // Reset the zero counter.
                count = 0;
            } else {
                // If the number is 0, increment the counter.
                count++;
            }
        }
        
        // If we finished the loop, all '1's were spaced correctly.
        return true;
    }
};