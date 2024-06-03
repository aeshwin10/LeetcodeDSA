class Solution {
public:
    int maxFrequency(map<char,int> mp) {
        int maxFreq = 0;
        for (auto& p : mp) {
            maxFreq = max(maxFreq, p.second);
        }
        return maxFreq;
}
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int n = s.size();
        map<char,int> mp;
        int ans = 0;
        bool flag = true;

        while(right<n){
            if(flag){
                mp[s[right]]++;
            }
            
            int maxFreq = maxFrequency(mp);
            maxLen = (right-left+1)-maxFreq;
            if(maxLen<=k){
                ans=max(ans,right-left+1);
                right++;
                flag = true;
            }
            else{
                mp[s[left]]--;
                left++;
                flag = false;
            }
        }
        return ans;
    }
};