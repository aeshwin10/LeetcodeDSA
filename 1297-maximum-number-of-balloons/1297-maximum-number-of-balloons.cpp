class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char c : text){
            mp[c]++;
        }

        string s = "balon";

        int ans = INT_MAX;
        for(char c : s){
            int tempFreq = mp[c];
            if(c=='l' || c=='o') tempFreq/=2;
            ans = min(ans, tempFreq);
        }
        return ans;
    }
};