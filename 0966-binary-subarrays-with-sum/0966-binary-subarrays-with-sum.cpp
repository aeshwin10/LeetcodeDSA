class Solution {
public:
    int findSubarr(vector<int>& nums, int goal){
        int sum = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+=nums[r];

            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findSubarr(nums, goal) - findSubarr(nums,(goal-1));
    }
};