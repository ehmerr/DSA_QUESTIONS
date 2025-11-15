#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // diff is (n+1) x (n+1) to avoid bounds checks when using r2+1 / c2+1
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        // Apply each query to the difference array
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        // Build horizontal prefix sums (row-wise)
        for (int i = 0; i <= n; ++i) {
            int run = 0;
            for (int j = 0; j <= n; ++j) {
                run += diff[i][j];
                diff[i][j] = run;
            }
        }

        // Build vertical prefix sums (col-wise)
        for (int j = 0; j <= n; ++j) {
            int run = 0;
            for (int i = 0; i <= n; ++i) {
                run += diff[i][j];
                diff[i][j] = run;
            }
        }

        // Extract the resulting n x n matrix
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result[i][j] = diff[i][j];

        return result;
    }
};
