#include <string>
#include <vector>

class Solution {
public:
    bool doesAliceWin(std::string s) {
        // Alice wins if she can make a valid move.
        // A single vowel ('a', 'e', 'i', 'o', or 'u') is a substring
        // with 1 vowel, which is an odd number.
        // Thus, if any vowel exists in the string, Alice has a winning move.
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true; // Found a vowel, so Alice has a valid move and wins.
            }
        }

        // No vowels were found in the entire string. Alice has no moves and loses.
        return false;
    }
};