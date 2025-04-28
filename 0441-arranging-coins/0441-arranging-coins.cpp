#include <iostream>

// Define LL as an alias for long to use as a larger integer type.
using LL = long;

class Solution {
public:
    // This function calculates the maximum number of complete rows of a staircase
    // you can build with n coins.
    int arrangeCoins(int n) {
        // Initialize the search interval.
        LL left = 1, right = n;
        // Run a binary search to find the maximum k rows that can be formed.
        while (left < right) {
            // Compute the middle point, be careful with overflow.
            LL mid = left + (right - left) / 2 + 1;
            // Sum of arithmetic series to find total coins used by k rows.
            LL totalCoinsUsed = mid * (mid + 1) / 2;
            // If the total coins used by k rows is more than n, look in the lower half.
            if (n < totalCoinsUsed) {
                right = mid - 1;
            } else { 
                // Otherwise, look in the upper half.
                left = mid;
            }
        }
        // Return the maximum number of complete rows that can be built.
        return left;
    }
};