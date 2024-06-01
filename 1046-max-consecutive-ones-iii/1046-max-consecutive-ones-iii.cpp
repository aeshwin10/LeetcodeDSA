class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxi = 0;
        int n = nums.size();
        int rem_zero = k;

        while(right<n){
            if(nums[right]==1){
                maxi=max(maxi, right-left+1);
                right++;
            }
            else{
                if(rem_zero>0){
                    rem_zero--;
                    maxi = max(maxi,right-left+1);
                    right++;
                }
                
                else{
                    while(nums[left]!=0){
                        left++;
                    }
                    left++;
                    rem_zero++;
                }
            }
        }
        return maxi;
    }
};