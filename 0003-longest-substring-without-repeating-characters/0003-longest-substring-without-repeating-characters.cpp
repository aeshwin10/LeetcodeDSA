class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int right = 0;
        int left = 0;
        int maxi=0;
        int n = s.size();
        map<char, int> mp;

        while (left < n && right < n) {
            mp[s[right]]++;

            while ((mp[s[right]])>1 && left<=right){
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi, right-left+1);
            right++;
        }
    return maxi;
    }
};
