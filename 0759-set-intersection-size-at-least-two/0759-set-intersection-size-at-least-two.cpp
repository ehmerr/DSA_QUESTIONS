#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        // Sort: Primary key is the end point (ascending), 
        // secondary key is the start point (descending).
        std::sort(intervals.begin(), intervals.end(), 
                  [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1]; // Sort by end point ascending
            }
            return a[0] > b[0]; // Sort by start point descending (crucial for greedy)
        });

        int ans = 0;
        // The two largest elements in the set S added so far.
        // Initialize to values guaranteed to be less than any possible start point.
        int mx = -1; 
        int secondMax = -2;

        for (const auto& interval : intervals) {
            const int start = interval[0];
            const int end = interval[1];

            // Case 1: Both mx and secondMax cover the current interval
            if (mx >= start && secondMax >= start) {
                continue;
            } 
            // Case 2: Only mx covers the current interval (secondMax < start)
            else if (mx >= start) {
                // Only one point is needed: add the largest point, 'end', to S
                secondMax = mx; // The old mx becomes the new secondMax
                mx = end;       // The new point is 'end'
                ans += 1;
            } 
            // Case 3: Neither mx nor secondMax covers the current interval (mx < start)
            else {
                // Two points are needed: add 'end' and 'end - 1' to S
                mx = end;       // The new largest point is 'end'
                secondMax = end - 1; // The new second largest point is 'end - 1'
                ans += 2;
            }
        }
        return ans;
    }
};