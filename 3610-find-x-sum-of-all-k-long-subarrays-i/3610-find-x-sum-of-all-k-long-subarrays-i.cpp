class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {  // ← int not long long
        int n = nums.size();
        vector<int> ans;  // ← int vector
        unordered_map<int,int> cnt;
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };
        multiset<pair<int,int>, decltype(cmp)> top(cmp), bot(cmp);
        long long windowSum = 0;  // keep internal sum long long for safety

        auto updateOld = [&](int v) {
            int f = cnt[v];
            if (f > 0) {
                auto p = make_pair(f, v);
                auto it = bot.find(p);
                if (it != bot.end()) bot.erase(it);
                else {
                    it = top.find(p);
                    if (it != top.end()) {
                        windowSum -= 1LL * f * v;
                        top.erase(it);
                    }
                }
            }
        };
        auto updateNew = [&](int v) {
            int f = cnt[v];
            if (f > 0) bot.insert({f, v});
        };

        for (int i = 0; i < n; ++i) {
            if (cnt[nums[i]]) updateOld(nums[i]);
            cnt[nums[i]]++;
            updateNew(nums[i]);

            if (i >= k) {
                int out = nums[i - k];
                updateOld(out);
                cnt[out]--;
                if (cnt[out] > 0) updateNew(out);
            }

            while ((int)top.size() < x && !bot.empty()) {
                auto it = prev(bot.end());
                windowSum += 1LL * it->first * it->second;
                top.insert(*it);
                bot.erase(it);
            }
            while (!bot.empty() && !top.empty()) {
                auto itBot = prev(bot.end());
                auto itTop = top.begin();
                if (cmp(*itTop, *itBot)) {
                    windowSum += 1LL * itBot->first * itBot->second;
                    windowSum -= 1LL * itTop->first * itTop->second;
                    bot.insert(*itTop);
                    top.insert(*itBot);
                    bot.erase(itBot);
                    top.erase(itTop);
                } else break;
            }

            if (i >= k - 1)
                ans.push_back((int)windowSum);  // cast to int here
        }

        return ans;
    }
};
