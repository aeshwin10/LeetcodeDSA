class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int lastIdx = nums.size()-1;
        int i=0;
        while(maxReach>=i && maxReach < lastIdx && i<lastIdx){
            maxReach=max(maxReach, i+nums[i]);
            i++;
        }
        return maxReach>=lastIdx;
    }
};