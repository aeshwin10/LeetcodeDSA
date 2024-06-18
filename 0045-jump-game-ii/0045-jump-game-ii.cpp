class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0;
        int right=0;
        
        int jumps=0;
        int n = nums.size();

        while(right<n-1){
            int maxi=0;
            jumps++;
            for(int i=left; i<=right; i++){
                maxi = max(maxi,nums[i]+i);
            }
            left = right+1;
            right = maxi;
        }
        return jumps;
    }
};