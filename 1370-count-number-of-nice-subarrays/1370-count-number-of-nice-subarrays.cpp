class Solution {
public:
    int findNiceOfK(vector<int> nums, int k){
        int left = 0;
        int right = 0;
        int odds = 0;
        int ans = 0;
        int n = nums.size();
        if(k<0) return 0;
        while(right<n){
            if(nums[right]%2==1){
                odds++;
            }
    
            if(odds>k){
                while(nums[left]%2==0){
                    left++;
                }
                odds--;
                left++;
            }
            ans+=(right-left+1);
            right++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (findNiceOfK(nums,k)-findNiceOfK(nums,(k-1)));
    }
};