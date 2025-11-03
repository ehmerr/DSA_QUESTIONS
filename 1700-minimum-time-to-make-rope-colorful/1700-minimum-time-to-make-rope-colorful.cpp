class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                // Remove the one with smaller time
                totalTime += min(neededTime[i], neededTime[i - 1]);
                // Keep the larger time for future comparison
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return totalTime;
    }
};
