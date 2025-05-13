class Solution {
const int MOD = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> cnt(26,0);

        for(char c:s){
            cnt[c-'a']++;
        }

        for(int i=0; i<t; i++){
            vector<long long> tmp(26, 0);
            for(int j=0; j<26; j++){
                if(j==25){
                    tmp[0] = (tmp[0] + cnt[j]) % MOD;
                    tmp[1] = (tmp[1] + cnt[j]) % MOD;
                }
                else{
                    tmp[j+1] = (tmp[j+1] + cnt[j]) % MOD;
                }
                
            }
            cnt = tmp;
        }
        long long ans = 0;
        for(auto &val : cnt){
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};