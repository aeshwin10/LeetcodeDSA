class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int k = nums.size()/2;
        unordered_map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        int c = 0;
        for(auto ele : mp){
            if(ele.second&1){
                return false;
            }
            c+= ele.second/2;
        }
        if(c==k){
            return true;
        }
        return false;

    }
};