#include <string>

class Solution {
public:
    /**
     * @brief Counts the number of substrings with only '1's.
     * @param s The input binary string.
     * @return The total count of '1'-only substrings, modulo 10^9 + 7.
     */
    int numSub(std::string s) {
        // Use 'long long' for counts to prevent overflow before modulo.
        long long totalCount = 0;
        long long currentStreak = 0;
        
        // Define the modulo value
        int MOD = 1e9 + 7; // This is equivalent to 1000000007

        // Iterate through each character in the string
        for (char c : s) {
            if (c == '1') {
                // If it's a '1', extend the current streak
                currentStreak++;
            } else {
                // If it's a '0', the streak is broken
                currentStreak = 0;
            }
            
            // Add the current streak count to the total.
            // A streak of length 'k' adds 'k' new substrings
            // (e.g., "111" adds "1", "11", "111").
            // Apply modulo at each addition step.
            totalCount = (totalCount + currentStreak) % MOD;
        }

        // The totalCount is already modulo-compliant.
        // Cast the final result back to int.
        return (int)totalCount;
    }
};