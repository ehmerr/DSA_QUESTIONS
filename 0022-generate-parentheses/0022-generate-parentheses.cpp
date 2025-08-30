#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        // Start the backtracking process with an empty string.
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current_string, int open_count, int close_count, int n) {
        // Base case: If the string is complete, add it to the result and stop.
        // A complete string has n pairs, so its length is 2 * n.
        if (current_string.length() == n * 2) {
            result.push_back(current_string);
            return;
        }

        // --- Recursive Step ---

        // Choice 1: Add an opening parenthesis '('
        // Condition: We can add an opening parenthesis only if we haven't used all n of them yet.
        if (open_count < n) {
            backtrack(result, current_string + "(", open_count + 1, close_count, n);
        }

        // Choice 2: Add a closing parenthesis ')'
        // Condition: We can add a closing parenthesis only if it doesn't exceed the number of open ones.
        // This is the key rule that ensures the parentheses are well-formed.
        if (close_count < open_count) {
            backtrack(result, current_string + ")", open_count, close_count + 1, n);
        }
    }
};