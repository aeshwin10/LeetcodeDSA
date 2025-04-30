class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto &ele : nums){
            string s = to_string(ele);
            if(s.size()%2==0) ans++;
        }
        return ans;
    }
};