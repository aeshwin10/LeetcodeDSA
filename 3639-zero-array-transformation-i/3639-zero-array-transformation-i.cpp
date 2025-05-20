class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> arr(n+1, 0);
        for(int i=0; i<m; i++){
            auto q = queries[i];
            arr[q[0]]++;
            arr[q[1]+1]--;
        }

        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0; i<n; i++){
            nums[i]-=arr[i];
            if(nums[i]>0){
                return false;
            } 
        }
        return true;
    }
};