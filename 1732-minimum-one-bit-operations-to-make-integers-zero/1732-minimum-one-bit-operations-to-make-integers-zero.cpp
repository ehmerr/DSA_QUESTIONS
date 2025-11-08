class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int msb = 31 - __builtin_clz(n);  // find index of highest set bit
        int mask = 1 << msb;
        return (1 << (msb + 1)) - 1 - minimumOneBitOperations(n ^ mask);
    }
};
