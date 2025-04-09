class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minEle = *min_element(nums.begin(), nums.end());
        if(k>minEle) return -1;
        unordered_map<int,int> mp;
        for(auto &num : nums){
            if(num>k){
                mp[num]++;
            }
        }
        return mp.size();
    }
};