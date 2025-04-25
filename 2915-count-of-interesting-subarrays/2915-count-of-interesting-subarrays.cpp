class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        long long preSum = 0;
        unordered_map<int, long long> mp;
        mp[0] = 1;

        for(auto &i : nums){
            if(i % modulo == k) preSum++;
            int rem = preSum % modulo;
            int needed = (rem - k + modulo) % modulo;

            ans += mp[needed];
            mp[rem]++;
        }
        return ans;
    }
};