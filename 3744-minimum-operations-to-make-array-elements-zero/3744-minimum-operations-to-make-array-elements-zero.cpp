#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long steps = 0;

            long long base = 1;   // start of range
            int depth = 1;        // step count

            while (base <= r) {
                long long end = base * 4 - 1;  // end of this range
                long long left = max(l, base);
                long long right = min(r, end);

                if (left <= right) {
                    steps += (right - left + 1) * 1LL * depth;
                }

                base *= 4;
                depth++;
            }

            result += (steps + 1) / 2;  // ceil(steps/2)
        }

        return result;
    }
};
