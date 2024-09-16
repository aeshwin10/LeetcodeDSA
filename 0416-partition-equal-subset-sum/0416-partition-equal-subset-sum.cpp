class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0)%2==1){
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0)/2;

        vector<int> dp(sum+1, false);
        dp[0] = true;

        for(int i=0; i<nums.size(); i++){
            for(int j=sum; j>=nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};