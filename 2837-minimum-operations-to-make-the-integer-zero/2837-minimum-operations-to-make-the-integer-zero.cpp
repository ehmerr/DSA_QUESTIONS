#include <numeric> // Required for std::popcount in C++20, but __builtin_popcountll is used here.

class Solution {
public:
  
     int makeTheIntegerZero(long long num1, long long num2) {
        // We are looking for the smallest integer k >= 1 such that num1 can be made zero
        // in k operations. The core equation is: num1 - k * num2 = sum_of_k_powers_of_2.
        
        // If num1 is smaller than num2, it's impossible to make it zero because
        // even with one operation subtracting the smallest power of 2 (2^0=1),
        // num1 - (1 + num2) would be negative. Since num2 >= 0, subsequent operations
        // will only make the result smaller.
        if (num1 < num2) {
            return -1;
        }

        // We iterate through the number of operations, k.
        // A loop up to 64 is a safe upper bound because the popcount of a 64-bit integer
        // cannot exceed 64. It is very likely a solution will be found with a small k.
        for (int k = 1; k <= 64; ++k) {
            // Calculate the remaining value after subtracting k * num2.
            long long target = num1 - (long long)k * num2;

            // This 'target' must be represented by the sum of 'k' powers of 2.
            // For this to be possible, two conditions must hold:
            // 1. popcount(target) <= k: The number of powers of 2 we have (k) must be at least
            //    the minimum required number (the number of set bits in target).
            // 2. k <= target: The sum of k powers of 2 is at least k (k * 2^0).
            if (__builtin_popcountll(target) <= k && k <= target) {
                // Since we are iterating from k=1 upwards, the first k that satisfies
                // the conditions is the minimum number of operations.
                return k;
            }
        }

        // If the loop completes without finding a suitable k, it's impossible.
        return -1;
    }
};