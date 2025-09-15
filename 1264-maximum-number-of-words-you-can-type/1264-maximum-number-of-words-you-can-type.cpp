#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        // Step 2: Create a set of broken characters for efficient lookup
        std::unordered_set<char> brokenSet;
        for (char c : brokenLetters) {
            brokenSet.insert(c);
        }

        // Use a stringstream to easily split the text into words
        std::stringstream ss(text);
        std::string word;
        int typableWordsCount = 0;

        // Step 4: Iterate through each word
        while (ss >> word) {
            bool canType = true;
            // Step 5: Check each character of the word
            for (char c : word) {
                if (brokenSet.count(c)) { // Check if the character is in the broken set
                    canType = false;
                    break; // Found a broken character, no need to check further
                }
            }
            // Step 6: Increment counter if the word is typable
            if (canType) {
                typableWordsCount++;
            }
        }

        // Step 7: Return the final count
        return typableWordsCount;
    }
};