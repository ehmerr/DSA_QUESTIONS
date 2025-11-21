#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        int n = s.length();
        int uniquePalindromes = 0;

        // Step 1: Find the first and last occurrence index for every character 'a' through 'z'.
        // This is done once to avoid repeated linear scans inside the loop.
        std::vector<int> first_occurrence(26, n); // Initialize with length n (out of bounds)
        std::vector<int> last_occurrence(26, -1); // Initialize with -1 (out of bounds)

        for (int i = 0; i < n; ++i) {
            int char_index = s[i] - 'a';
            first_occurrence[char_index] = std::min(first_occurrence[char_index], i);
            last_occurrence[char_index] = std::max(last_occurrence[char_index], i);
        }

        // Step 2: Iterate through every possible outer character 'a' through 'z' (c1).
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            int outer_index = c1 - 'a';
            int first_idx = first_occurrence[outer_index];
            int last_idx = last_occurrence[outer_index];

            // If the character appears, and the distance between the first and last
            // occurrence is at least 2, a length-3 palindrome of the form "c1_c1" is possible.
            if (last_idx - first_idx >= 2) {
                // The possible center characters (c2) must lie strictly between
                // first_idx and last_idx.
                std::unordered_set<char> center_characters;

                // Step 3: Iterate over the substring s[first_idx + 1 ... last_idx - 1]
                // and collect all unique characters found there.
                for (int j = first_idx + 1; j < last_idx; ++j) {
                    center_characters.insert(s[j]);
                }

                // The number of unique center characters is the number of unique
                // length-3 palindromes that can be formed with 'c1' as the outer character.
                uniquePalindromes += center_characters.size();
            }
        }

        return uniquePalindromes;
    }
};