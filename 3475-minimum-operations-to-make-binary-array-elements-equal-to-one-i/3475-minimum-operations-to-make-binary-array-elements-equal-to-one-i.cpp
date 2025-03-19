class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> nums1 = nums;
        for(int right=0; right<n-2; right++){
            if(nums1[right]==0){
                nums1[right] = 1;
                nums1[right+1] ^= 1;
                nums1[right+2] ^= 1;
                ans++;
            }
        }
        for(int right = n-3; right<n; right++){
            if(nums1[right]==0){
                return -1;
            }
        }
        return ans;
    }
};