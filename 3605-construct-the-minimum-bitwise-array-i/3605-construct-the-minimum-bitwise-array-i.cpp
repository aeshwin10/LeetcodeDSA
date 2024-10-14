class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(const auto& i : nums){
            if(i==2){
                ans.push_back(-1);
                continue;
            }
            for(int j=1; j<31; j++){
                if(i & (1<<j)){
                    continue;
                }
                ans.push_back(i ^ (1 << (j-1)));
                break;
            }
        }
        return ans;
    }
};