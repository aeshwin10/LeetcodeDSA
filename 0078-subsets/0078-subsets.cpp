class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int bitMask = (1<<n);

        vector<vector<int>> ans;  //Time Complexity - O(2^n * n)

        for(int i = 0; i<bitMask; i++){
            vector<int> arr;
            
            for(int j = 0; j<n; j++){
                if(((1<<j) & i)!=0){
                    arr.push_back(nums[j]);
                }
                
            }
            ans.push_back(arr);   
        }
        return ans;
    }
};