#include <vector>
#include <map>
#include <set>
#include <tuple>

class MovieRentingSystem {
private:
    // Maps movie_id -> set of {price, shop} for available movies
    std::map<int, std::set<std::pair<int, int>>> available_movies;

    // Set of {price, shop, movie} for rented movies
    std::set<std::tuple<int, int, int>> rented_movies;
    
    // Maps {shop, movie} -> price for quick lookups
    std::map<std::pair<int, int>, int> prices;

public:
    MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            
            prices[{shop, movie}] = price;
            available_movies[movie].insert({price, shop});
        }
    }
    
    std::vector<int> search(int movie) {
        std::vector<int> result;
        if (available_movies.find(movie) == available_movies.end()) {
            return result;
        }
        
        int count = 0;
        for (const auto& p : available_movies[movie]) {
            if (count >= 5) break;
            result.push_back(p.second); // p.second is the shop
            count++;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = prices[{shop, movie}];
        
        available_movies[movie].erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[{shop, movie}];

        rented_movies.erase({price, shop, movie});
        available_movies[movie].insert({price, shop});
    }
    
    std::vector<std::vector<int>> report() {
        std::vector<std::vector<int>> result;
        int count = 0;
        for (const auto& t : rented_movies) {
            if (count >= 5) break;
            result.push_back({std::get<1>(t), std::get<2>(t)}); // {shop, movie}
            count++;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */