class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        for(int right=2; right<n; right++){
            int midVal = nums[right-1];
            if(2 * (nums[right]+nums[left])==midVal) ans++;
            left++;
        }
        return ans;
    }
};