class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int val1 = nums[0];
        int maxDiff = val1-nums[1];

        long long ans = (long long)maxDiff * nums[n-1];

        vector<int> maxSuffix(n, 0);
        maxSuffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxSuffix[i] = max(maxSuffix[i+1], nums[i]);
        }

        for(int i=1; i<n-1; i++){
            maxDiff = max(maxDiff, val1 - nums[i]);
            val1 = max(val1, nums[i]);
            ans = max(ans, (long long)maxDiff * maxSuffix[i+1]);
        }

        return max(0ll,ans);
    }
};