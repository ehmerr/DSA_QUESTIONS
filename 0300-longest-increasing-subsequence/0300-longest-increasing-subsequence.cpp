#include <vector>
#include <algorithm> // For std::lower_bound

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        // 'sub' stores the smallest tail of all increasing subsequences with length i+1 at sub[i].
        std::vector<int> sub;

        for (int num : nums) {
            // Find an iterator to the first element in 'sub' that is not less than 'num'.
            auto it = std::lower_bound(sub.begin(), sub.end(), num);

            if (it == sub.end()) {
                // If 'num' is greater than all elements in 'sub', append it.
                // This extends the current longest subsequence.
                sub.push_back(num);
            } else {
                // Replace the element pointed to by 'it' with 'num'.
                // This makes the subsequence tail smaller, allowing for more future elements.
                *it = num;
            }
        }

        return sub.size();
    }
};