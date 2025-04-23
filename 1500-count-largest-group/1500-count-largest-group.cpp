class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++){
            string s = to_string(i);
            int sum = 0;
            for(char c : s){
                sum  = sum + (c - '0');
            }
            mp[sum]++;
        }
        int maxi = 1;
        int ans = 0;
        for(auto [key, val] : mp){
            if(val > maxi){
                ans = 1;
                maxi = val;
            }
            else if(val == maxi){
                ans++;
            }
        }
        return ans;
    }
};