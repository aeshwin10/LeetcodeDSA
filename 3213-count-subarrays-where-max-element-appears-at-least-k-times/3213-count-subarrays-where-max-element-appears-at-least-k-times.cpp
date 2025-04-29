class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;
        int left = 0;
        int maxEle = *max_element(nums.begin(), nums.end());

        for(int right = 0; right<n; right++){
            mp[nums[right]]++;
            while(mp[maxEle]>=k){
                ans += (n-right);
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};