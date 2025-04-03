class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        unordered_map<string, int> mp;
        for(auto word : wordDict){
            mp[word]++;
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;

        for(int i=1; i<=s.size(); i++){
            //string temp = s[i];
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string tempWord = s.substr(j, i-j);
                    if(mp[tempWord]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};