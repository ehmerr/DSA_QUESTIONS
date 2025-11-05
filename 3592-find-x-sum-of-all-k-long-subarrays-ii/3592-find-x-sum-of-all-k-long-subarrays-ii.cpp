class Solution {
public:
    struct Node {
        int freq, val;
        bool operator<(const Node &other) const {
            if (freq != other.freq) return freq < other.freq;
            return val < other.val;
        }
    };

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<int,int> cnt;
        multiset<Node> top, rest;
        long long sum = 0;

        auto moveUp = [&]() {
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                top.insert(*it);
                sum += 1LL * it->freq * it->val;
                rest.erase(it);
            }
        };

        auto balance = [&]() {
            while (!top.empty() && !rest.empty()) {
                auto low = top.begin(), high = prev(rest.end());
                if (*low < *high) {
                    sum -= 1LL * low->freq * low->val;
                    sum += 1LL * high->freq * high->val;
                    rest.insert(*low);
                    top.insert(*high);
                    top.erase(low);
                    rest.erase(high);
                } else break;
            }
        };

        auto removeState = [&](int v) {
            int f = cnt[v];
            if (f == 0) return;
            Node cur{f, v};
            auto it = top.find(cur);
            if (it != top.end()) {
                sum -= 1LL * it->freq * it->val;
                top.erase(it);
            } else {
                it = rest.find(cur);
                if (it != rest.end()) rest.erase(it);
            }
        };

        auto addState = [&](int v) {
            int f = cnt[v];
            Node cur{f, v};
            if ((int)top.size() < x) {
                top.insert(cur);
                sum += 1LL * f * v;
            } else {
                auto it = top.begin();
                if (*it < cur) {
                    rest.insert(*it);
                    sum -= 1LL * it->freq * it->val;
                    top.erase(it);
                    top.insert(cur);
                    sum += 1LL * f * v;
                } else {
                    rest.insert(cur);
                }
            }
        };

        // initialize first window
        for (int i = 0; i < k; ++i) {
            if (cnt[nums[i]]) removeState(nums[i]);
            cnt[nums[i]]++;
            addState(nums[i]);
            balance();
            moveUp();
        }
        ans.push_back(sum);

        // slide
        for (int i = k; i < n; ++i) {
            int out = nums[i - k], in = nums[i];
            removeState(out);
            if (--cnt[out] > 0) addState(out);
            if (cnt[in]) removeState(in);
            cnt[in]++; addState(in);
            balance();
            moveUp();
            ans.push_back(sum);
        }

        return ans;
    }
};
