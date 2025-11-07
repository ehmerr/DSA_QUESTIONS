#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    /**
     * @brief Checks if it's possible to make every city have at least P power
     * using at most k new stations.
     */
    bool is_possible(const vector<int>& stations, int n, int r, long long k, long long P) {
        // We need 64-bit integers for power calculations.
        vector<long long> power_deltas(n + 1, 0);

        // 1. Calculate initial power
        for (int i = 0; i < n; ++i) {
            long long L = max(0, i - r);
            long long R = min(n - 1, i + r);
            power_deltas[L] += stations[i];
            power_deltas[R + 1] -= stations[i];
        }

        vector<long long> initial_power(n);
        long long current_initial_power = 0;
        for (int i = 0; i < n; ++i) {
            current_initial_power += power_deltas[i];
            initial_power[i] = current_initial_power;
        }

        // 2. Greedily add stations
        long long stations_added = 0;
        vector<long long> added_power_diff(n + 1, 0);
        long long current_added_power = 0;

        for (int i = 0; i < n; ++i) {
            current_added_power += added_power_diff[i];
            long long current_total_power = initial_power[i] + current_added_power;

            if (current_total_power < P) {
                long long needed = P - current_total_power;
                stations_added += needed;
                if (stations_added > k) {
                    return false;
                }

                current_added_power += needed;

                long long end_index_plus_1 = min((long long)n, (long long)i + 2 * r + 1);
                if (end_index_plus_1 < n + 1) {
                    added_power_diff[end_index_plus_1] -= needed;
                }
            }
        }
        return true;
    }

public:
    /**
     * @brief Finds the maximum possible minimum power of a city.
     * (Renamed from maximizeMinPower to maxPower to match the test harness)
     */
    long long maxPower(vector<int>& stations, int r, int k) { // <-- Renamed this function
        int n = stations.size();

        long long low = 0;
        long long high = 0;
        for (int s : stations) {
            high += s;
        }
        high += k;

        long long ans = 0;

        while (low <= high) {
            long long mid_P = low + (high - low) / 2;
            if (is_possible(stations, n, r, k, mid_P)) {
                ans = mid_P;
                low = mid_P + 1;
            } else {
                high = mid_P - 1;
            }
        }

        return ans;
    }
};