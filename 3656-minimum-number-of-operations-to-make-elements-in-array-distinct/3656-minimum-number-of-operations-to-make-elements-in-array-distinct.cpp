class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int idx = -1;
        for(int i=n-1; i>=0; i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            return 0;
        }
        return (idx + 3) / 3;
    }
};