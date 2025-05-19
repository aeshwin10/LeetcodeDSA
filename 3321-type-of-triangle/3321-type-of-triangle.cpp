class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> s;
        s.insert(nums[0]);
        s.insert(nums[1]);
        s.insert(nums[2]);
        if(nums[2] >= nums[0]+nums[1] || nums[0] >= nums[2]+nums[1] || nums[1] >= nums[2]+nums[0]){
            return "none";
        }
        if(s.size()==1){
            return "equilateral";
        }
        else if(s.size()==2){
            return "isosceles";
        }
        else{
            return "scalene";
        }
    }
};