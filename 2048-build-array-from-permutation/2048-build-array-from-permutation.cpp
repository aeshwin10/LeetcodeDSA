class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int curEle = nums[nums[i]];
            ans.push_back(curEle);
        }
        return ans;
    }
};