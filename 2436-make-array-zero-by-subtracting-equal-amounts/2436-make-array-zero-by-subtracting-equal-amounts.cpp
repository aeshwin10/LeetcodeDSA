class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                count++;
                int temp = nums[i];
                for(int j=i; j<n; j++){
                    nums[j]-=temp;
                }
            }
        }
        return count;
    }
};