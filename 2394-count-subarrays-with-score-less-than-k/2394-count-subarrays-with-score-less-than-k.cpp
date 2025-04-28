class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0ll;
        
        int left = 0;
        long long curSum = 0;
        for(int right =0; right<n; right++){
            curSum+=nums[right];
            while(curSum * (right-left+1) >= k){
                curSum -= nums[left];
                left++;
            }
            ans += right - left + 1;  //All subarrays ending at right and starting anywhere from left to right are valid
        }        
        return ans;
    }
};