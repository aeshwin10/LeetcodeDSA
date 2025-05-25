class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = -1;
        int curSum = 0;
        long long totalSum= accumulate(nums.begin(), nums.end(), 0ll);

        int left = 0;
        
        for(int right = 0; right<n; right++){
            curSum+=nums[right];
            while(curSum > totalSum - x && left<=right){
                curSum-=nums[left];
                left++;
            }
            if(curSum == totalSum - x) {
                ans = max(ans, right-left+1);
            }
        }
        if(ans==-1){
            return -1;
        }
        ans = (n-ans);
        return ans;
    }
};