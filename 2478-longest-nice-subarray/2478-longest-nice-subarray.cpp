class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        
        int left = 0;
        int tempOr = nums[0];
        for(int right = 1; right<n; right++){
            while((tempOr & nums[right])!=0){
                tempOr -= nums[left];
                left++;
            }
            tempOr = (tempOr | nums[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};