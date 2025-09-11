#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

class Solution {
private:
    // Helper function to check if a character is a vowel (case-insensitive).
    bool isVowel(char c) {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    std::string sortVowels(std::string s) {
        // Step 1: Extract all vowels from the string.
        std::string vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort the collected vowels based on their ASCII values.
        std::sort(vowels.begin(), vowels.end());

        // Step 3: Place the sorted vowels back into the original string's
        // vowel positions, maintaining the order.
        int vowel_index = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = vowels[vowel_index++];
            }
        }

        return s;
    }
};