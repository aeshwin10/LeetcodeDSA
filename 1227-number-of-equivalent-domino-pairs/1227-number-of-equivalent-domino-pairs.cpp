class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return p.first * 31 + p.second;
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int,int>, int, hash_pair> mp;

        for(auto& d : dominoes){
            if(d[0] > d[1]) swap(d[0], d[1]);
            mp[{d[0], d[1]}]++;
        }

        int ans = 0;
        for(auto& [d, freq] : mp){
            ans += freq * (freq - 1) / 2;
        }
        return ans;
    
    }
};