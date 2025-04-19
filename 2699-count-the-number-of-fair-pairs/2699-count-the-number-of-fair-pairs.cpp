class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = 0, k = nums.size() - 1, j = k; i < nums.size() && i < k; ++i){
            while (j > i && nums[j] + (long long)nums[i] >= lower) --j;
            while (k > i && nums[k] + (long long)nums[i] > upper) --k;
            res += (k - max(j, i));
        }
        return res;
    
    }
};