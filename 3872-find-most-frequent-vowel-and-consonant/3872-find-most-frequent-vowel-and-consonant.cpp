#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFreqSum(std::string s) {
        // Create a frequency map for all 26 lowercase letters.
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        // Iterate through the 26 letters to find the max frequencies.
        for (int i = 0; i < 26; ++i) {
            char currentChar = 'a' + i;
            bool is_vowel = (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u');

            if (is_vowel) {
                // Update the max frequency found for any vowel.
                maxVowelFreq = std::max(maxVowelFreq, counts[i]);
            } else {
                // Update the max frequency found for any consonant.
                maxConsonantFreq = std::max(maxConsonantFreq, counts[i]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};