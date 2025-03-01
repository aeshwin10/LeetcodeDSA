class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int count = 0;
        int i = 0;

        bool lastChangedToZero = false;
        while(i<n-1){
            if(nums[i]==0){
                count++;
                i++;
            }
            else if(nums[i]==nums[i+1]){
                if(i==n-2){
                    lastChangedToZero = true;
                }
                ans.push_back(nums[i]*2);
                count++;
                i+=2;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        if(!lastChangedToZero){
            ans.push_back(nums[n-1]);
        }
        while(count--){
            ans.push_back(0);
        }
        return ans;
    }
};