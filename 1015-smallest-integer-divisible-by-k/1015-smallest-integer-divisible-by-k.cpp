class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // Edge Case: 
        // A number consisting only of '1's is always odd and never ends in 0 or 5.
        // Therefore, if k is even or divisible by 5, it can never divide such a number.
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int remainder = 0;
        
        // We iterate up to k times. According to Pigeonhole Principle,
        // if a solution exists, it must be found within k iterations.
        for (int length = 1; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            
            if (remainder == 0) {
                return length;
            }
        }

        return -1;
    }
};