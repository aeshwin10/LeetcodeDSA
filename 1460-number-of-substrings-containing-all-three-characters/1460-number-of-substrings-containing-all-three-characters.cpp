class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        for(int right = 0; right<n; right++){
            mp[s[right]]++;
            while(mp.size()>=3){
                ans+=(n-right);
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};