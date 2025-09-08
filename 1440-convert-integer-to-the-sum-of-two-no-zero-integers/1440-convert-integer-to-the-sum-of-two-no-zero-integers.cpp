#include <vector>

class Solution {
public:
    // Helper function to check if a number contains the digit '0'
    bool containsZero(int num) {
        if (num == 0) {
            return true; // Although the problem specifies A and B are positive, this handles edge cases
        }
        while (num > 0) {
            if (num % 10 == 0) {
                return true;
            }
            num /= 10;
        }
        return false;
    }

    std::vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if (!containsZero(A) && !containsZero(B)) {
                return {A, B};
            }
        }
        return {}; // Should not be reached based on problem constraints (n >= 2)
    }
};