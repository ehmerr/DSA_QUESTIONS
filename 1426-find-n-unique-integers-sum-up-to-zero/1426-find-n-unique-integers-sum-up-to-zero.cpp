#include <vector> // Required for std::vector

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        result.reserve(n); // Optional: pre-allocate memory for efficiency

        // Add pairs of (i, -i) to the vector.
        // Integer division n / 2 correctly handles both even and odd n.
        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }

        // If n is odd, the loop above will have generated n-1 elements.
        // We add 0 to complete the array without changing the sum.
        if (n % 2 != 0) {
            result.push_back(0);
        }

        return result;
    }
};