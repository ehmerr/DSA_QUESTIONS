#include <vector>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long mod = 1e9 + 7;
        
        // dp[i] stores the number of people who newly learn the secret on day i.
        std::vector<long long> dp(n + 1, 0);
        
        // On day 1, one person knows the secret.
        dp[1] = 1;

        // 'sharers' tracks the number of people currently sharing the secret.
        long long sharers = 0;
        
        // 'totalKnown' tracks the total number of people who know the secret on the current day.
        long long totalKnown = 1;

        for (int i = 2; i <= n; ++i) {
            // Add new sharers: people who learned the secret 'delay' days ago.
            long long newlySharing = (i - delay >= 1) ? dp[i - delay] : 0;

            // Remove people who forget: people who learned the secret 'forget' days ago.
            long long newlyForgetting = (i - forget >= 1) ? dp[i - forget] : 0;
            
            // Update the number of people who are currently sharing.
            sharers = (sharers + newlySharing - newlyForgetting + mod) % mod;
            
            // The number of new people on day 'i' is the number of people currently sharing.
            dp[i] = sharers;

            // Update the total number of people who know the secret.
            totalKnown = (totalKnown + dp[i] - newlyForgetting + mod) % mod;
        }

        return totalKnown;
    }
};