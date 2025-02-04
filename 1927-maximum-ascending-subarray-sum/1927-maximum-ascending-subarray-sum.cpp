class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = *max_element(nums.begin(), nums.end());
        int temp = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                temp+=nums[i];
                ans = max(temp, ans);
            }
            else{
                temp = nums[i];
            }
        }
        return ans;
    }
};