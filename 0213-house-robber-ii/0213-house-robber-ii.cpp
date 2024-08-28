class Solution {
    int doingRobbery(vector<int> &nums, int ind, int st, vector<int> &dp){
        if(ind < st) return 0;
        if(ind == st) return nums[st];
        if(dp[ind] != -1) return dp[ind];
        int robbed = nums[ind] + doingRobbery(nums, ind-2, st, dp);
        int notRobbed = 0 + doingRobbery(nums, ind-1, st, dp);
        return dp[ind] = max(robbed, notRobbed);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp1(n, -1);
        int withoutLast = doingRobbery(nums, n-2, 0, dp1);
        
        vector<int> dp2(n, -1);
        int withoutFirst = doingRobbery(nums, n-1, 1, dp2);
        
        return max(withoutLast, withoutFirst);
    }
};