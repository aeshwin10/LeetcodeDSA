class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        bool rev = false;
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++){
            string curWord = words[i];
            mp[curWord]++;
        }

        for(auto& [word, val] : mp){
            string revWord = (string() + word[1] + word[0]);
            if(revWord == word){
                if(val&1){
                    rev = true;
                    ans+=(val-1)*2;
                }
                else ans+=val*2;
            }
            else if(mp.count(revWord)){
                int pairs = min(val, mp[revWord]);
                ans+=pairs * 4;
                mp[revWord] = 0;
                mp[word] = 0;
            }
        }
        if(rev) ans+=2;
        return ans;
    }
};