class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // We use boolean arrays for efficient tracking.
        // The size is 9 (for each row/col/box) x 10 (for digits 1-9).
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};

        // Iterate through each cell of the 9x9 board.
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells.
                if (board[r][c] == '.') {
                    continue;
                }

                // Convert char digit to an integer index (e.g., '5' -> 5).
                int num = board[r][c] - '0';

                // Calculate the index for the 3x3 sub-box.
                // This formula maps each (r, c) coordinate to a unique box index from 0 to 8.
                // [Image of Sudoku grid with 3x3 sub-boxes numbered 0 to 8]
                int box_idx = (r / 3) * 3 + (c / 3);

                // Check for violations:
                // 1. If the number is already in the current row's tracker.
                // 2. If the number is already in the current column's tracker.
                // 3. If the number is already in the current 3x3 box's tracker.
                if (rows[r][num] || cols[c][num] || boxes[box_idx][num]) {
                    return false; // Found a violation, so the board is invalid.
                }

                // If no violation, mark the number as seen for the current
                // row, column, and box.
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_idx][num] = true;
            }
        }

        // If we complete the loop without finding any violations, the board is valid.
        return true;
    }
};