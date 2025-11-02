class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0=empty, 1=guard, 2=wall
        for (auto &g : guards) grid[g[0]][g[1]] = 1;
        for (auto &w : walls)  grid[w[0]][w[1]] = 2;

        vector<vector<bool>> guarded(m, vector<bool>(n, false));

        // row scan
        for (int i = 0; i < m; ++i) {
            bool seen = false;
            for (int j = 0; j < n; ++j) { // left → right
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) guarded[i][j] = true;
            }
            seen = false;
            for (int j = n - 1; j >= 0; --j) { // right → left
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) guarded[i][j] = true;
            }
        }

        // column scan
        for (int j = 0; j < n; ++j) {
            bool seen = false;
            for (int i = 0; i < m; ++i) { // top → bottom
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) guarded[i][j] = true;
            }
            seen = false;
            for (int i = m - 1; i >= 0; --i) { // bottom → top
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) guarded[i][j] = true;
            }
        }

        int unguarded = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0 && !guarded[i][j])
                    ++unguarded;

        return unguarded;
    }
};
