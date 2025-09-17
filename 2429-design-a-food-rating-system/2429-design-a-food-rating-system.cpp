#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class FoodRatings {
private:
    // Map food name to its {rating, cuisine}
    map<string, pair<int, string>> food_info;

    // Map cuisine to a sorted set of { -rating, food_name }
    // We use -rating to make the set sort in descending order of rating
    // The set automatically handles lexicographical sorting for ties
    map<string, set<pair<int, string>>> cuisine_ratings;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            food_info[foods[i]] = {ratings[i], cuisines[i]};
            cuisine_ratings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        // 1. Get old rating and cuisine
        auto& [oldRating, cuisine] = food_info[food];

        // 2. Remove the old entry from the cuisine's sorted set
        cuisine_ratings[cuisine].erase({-oldRating, food});

        // 3. Insert the new entry
        cuisine_ratings[cuisine].insert({-newRating, food});

        // 4. Update the food's rating in the info map
        food_info[food].first = newRating;
    }

    string highestRated(string cuisine) {
        // The first element in the set will be the highest rated
        // because we stored the ratings as negative numbers.
        // begin() returns an iterator to the smallest element.
        auto it = cuisine_ratings[cuisine].begin();
        return it->second; // Return the food name
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */