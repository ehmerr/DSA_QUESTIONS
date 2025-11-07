#include <vector>
#include <numeric> // For std::iota
#include <set>
#include <map>

using namespace std;

/**
 * @brief Implements a Disjoint Set Union (DSU) data structure.
 * This is used to efficiently group connected power stations into "grids".
 */
class DSU {
private:
    vector<int> parent;

public:
    /**
     * @brief Initializes the DSU structure for n elements.
     * @param n The number of elements (stations), typically c + 1 for 1-based indexing.
     */
    DSU(int n) {
        parent.resize(n);
        // Fills the parent array with 0, 1, 2, ...
        iota(parent.begin(), parent.end(), 0);
    }

    /**
     * @brief Finds the representative (root) of the set containing element i.
     * Implements path compression for efficiency.
     * @param i The element to find.
     * @return The representative (root) of the set.
     */
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    /**
     * @brief Unites the sets containing elements i and j.
     * @param i An element in the first set.
     * @param j An element in the second set.
     */
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Simple union: make one root the parent of the other
            parent[root_j] = root_i;
        }
    }
};

class Solution {
public:
    /**
     * @brief Processes maintenance queries on a power grid.
     * (Renamed from getResults to processQueries to match the test harness)
     * @param c The number of power stations (1 to c).
     * @param connections The list of cables connecting stations.
     * @param queries The list of maintenance (type 1) or offline (type 2) queries.
     * @return A vector of results for all type 1 queries.
     */
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        // 1. Initialize DSU and build the grids
        // We use c + 1 for 1-based station indexing (stations 1 to c)
        DSU dsu(c + 1);
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        // 2. State Tracking
        
        // grid_members maps the ROOT of a grid to a set of its ONLINE members.
        // Using std::set automatically keeps the IDs sorted.
        map<int, set<int>> grid_members;
        
        // is_online tracks the current status of each station for O(1) checks.
        vector<bool> is_online(c + 1, true);

        // 3. Populate the initial state of grid_members
        // Initially, all stations are online.
        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i);
            grid_members[root].insert(i);
        }

        // 4. Process queries
        vector<int> results;
        for (const auto& query : queries) {
            int type = query[0];
            int x = query[1]; // The station ID

            if (type == 1) {
                // --- Query Type 1: Maintenance Check ---
                
                if (is_online[x]) {
                    // Station x is online, it resolves the check itself.
                    results.push_back(x);
                } else {
                    // Station x is offline. Find the smallest online station in its grid.
                    int root = dsu.find(x);
                    
                    if (grid_members[root].empty()) {
                        // The entire grid is offline
                        results.push_back(-1);
                    } else {
                        // Get the smallest element from the set (O(1) for set)
                        results.push_back(*grid_members[root].begin());
                    }
                }
            } else if (type == 2) {
                // --- Query Type 2: Go Offline ---
                
                // Only process if the station is not already offline
                if (is_online[x]) {
                    is_online[x] = false;
                    
                    // Find the grid x belongs to
                    int root = dsu.find(x);
                    
                    // Remove x from its grid's set of *online* members
                    // This is an O(log c) operation.
                    grid_members[root].erase(x);
                }
            }
        }

        return results;
    }
};