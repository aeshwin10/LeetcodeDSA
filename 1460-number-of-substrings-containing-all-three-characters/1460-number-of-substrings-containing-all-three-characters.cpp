class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int right = 0;
        int n = s.size();
        int lefti = 10e5;
        int ans=0;
        
        

        while(right<n){
            mp[s[right]]=right;
            if(mp.size()>=3){
                for(pair<char,int> e: mp){
                    lefti = min(lefti,e.second); 
                }
                ans+=lefti+1;
                lefti=10e7;
            }
            right++;
        }
        return ans;
    }
};