class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> friends_to_teach;
        unordered_set<int> friends_not_speaking;
        for (const auto& friendship : friendships) {
            bool can_communicate = false;
            for (int lang1 : languages[friendship[0] - 1]) {
                for (int lang2 : languages[friendship[1] - 1]) {
                    if (lang1 == lang2) {
                        can_communicate = true;
                        break;
                    }
                }
                if (can_communicate) {
                    break;
                }
            }
            if (!can_communicate) {
                friends_to_teach.insert(friendship[0] - 1);
                friends_to_teach.insert(friendship[1] - 1);
            }
        }
        
        if (friends_to_teach.empty()) {
            return 0;
        }

        int min_teachings = friends_to_teach.size();
        
        for (int lang_to_teach = 1; lang_to_teach <= n; ++lang_to_teach) {
            int current_teachings = 0;
            for (int friend_to_teach : friends_to_teach) {
                bool already_speaks_lang = false;
                for (int lang : languages[friend_to_teach]) {
                    if (lang == lang_to_teach) {
                        already_speaks_lang = true;
                        break;
                    }
                }
                if (!already_speaks_lang) {
                    current_teachings++;
                }
            }
            min_teachings = min(min_teachings, current_teachings);
        }
        
        return min_teachings;
    }
};