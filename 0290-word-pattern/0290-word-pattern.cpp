#include <string>
#include <sstream>      // For std::stringstream
#include <unordered_map> // For std::unordered_map

class Solution {
public:
    /**
     * @brief Determines if a string 's' follows the pattern 'pattern'.
     * @param pattern The pattern string (e.g., "abba").
     * @param s The input string of words (e.g., "dog cat cat dog").
     * @return true if 's' follows the 'pattern', false otherwise.
     */
    bool wordPattern(std::string pattern, std::string s) {
        // Maps to check the bijective (one-to-one) relationship
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;
        
        // Use stringstream to easily split the string 's' by spaces
        std::stringstream ss(s);
        std::string word;
        
        // Iterate through each character in the pattern
        for (char c : pattern) {
            // Try to read the next word from 's'.
            // If it fails, 's' has fewer words than 'pattern' has characters.
            if (!(ss >> word)) {
                return false;
            }
            
            // Check 1: Does the char 'c' already map to a *different* word?
            if (charToWord.count(c) && charToWord[c] != word) {
                return false;
            }
            
            // Check 2: Does the 'word' already map to a *different* char?
            if (wordToChar.count(word) && wordToChar[word] != c) {
                return false;
            }
            
            // If no conflicts, establish the two-way mapping
            charToWord[c] = word;
            wordToChar[word] = c;
        }
        
        // After iterating through the pattern, check if 's' has any extra words.
        // If it does, the lengths don't match.
        if (ss >> word) {
            return false;
        }
        
        // If all checks passed, the pattern is valid
        return true;
    }
};