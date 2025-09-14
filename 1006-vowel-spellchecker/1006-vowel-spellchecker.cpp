#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

class Solution {
public:
    /**
     * @brief Checks a list of queries against a wordlist using three matching rules.
     * * @param wordlist The list of correct words.
     * @param queries The list of words to check.
     * @return A vector of corrected words or empty strings for no matches.
     */
    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
        // Data structure for Rule 1: Exact, case-sensitive match
        std::unordered_set<std::string> words_perfect(wordlist.begin(), wordlist.end());

        // Data structures for Rules 2 and 3
        std::unordered_map<std::string, std::string> words_case_insensitive;
        std::unordered_map<std::string, std::string> words_vowel_error;

        // Pre-process the wordlist to populate the maps
        for (const std::string& word : wordlist) {
            std::string lower = to_lower(word);
            std::string devoweled = to_devowel(lower);
            
            // Use try_emplace to insert only if the key is not already present.
            // This preserves the first occurrence from the wordlist.
            words_case_insensitive.try_emplace(lower, word);
            words_vowel_error.try_emplace(devoweled, word);
        }

        std::vector<std::string> result;
        result.reserve(queries.size()); // Pre-allocate memory for efficiency

        for (const std::string& query : queries) {
            // Rule 1: Check for an exact match
            if (words_perfect.count(query)) {
                result.push_back(query);
                continue;
            }

            // Rule 2: Check for a case-insensitive match
            std::string lower_query = to_lower(query);
            auto it_case = words_case_insensitive.find(lower_query);
            if (it_case != words_case_insensitive.end()) {
                result.push_back(it_case->second);
                continue;
            }

            // Rule 3: Check for a vowel error match
            std::string devowel_query = to_devowel(lower_query);
            auto it_vowel = words_vowel_error.find(devowel_query);
            if (it_vowel != words_vowel_error.end()) {
                result.push_back(it_vowel->second);
                continue;
            }

            // If no match is found, add an empty string
            result.push_back("");
        }
        return result;
    }

private:
    /**
     * @brief Helper function to convert a string to lowercase.
     */
    std::string to_lower(const std::string& s) {
        std::string lower_s = s;
        std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return lower_s;
    }

    /**
     * @brief Helper function to create a "devoweled" pattern from a lowercase string.
     * Vowels ('a', 'e', 'i', 'o', 'u') are replaced with a placeholder '#'.
     */
    std::string to_devowel(const std::string& lower_s) {
        std::string devoweled_s = lower_s;
        for (char& c : devoweled_s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#'; // Use a consistent placeholder for vowels
            }
        }
        return devoweled_s;
    }
};