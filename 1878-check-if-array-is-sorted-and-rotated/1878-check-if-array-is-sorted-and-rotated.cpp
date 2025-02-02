class Solution {
public:
    bool check(vector<int>& nums) {
        int rotations = 0;
        for(int i=0; i<nums.size(); i++){ 
            int currEle = nums[i];
            int rightEle = nums[(i+1) % nums.size()];
            if(currEle > rightEle) rotations++;
            if(rotations>1) return false;
        }
        return true;
    }
};