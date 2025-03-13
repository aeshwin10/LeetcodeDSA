class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        int low = 0;
        int high = queries.size();
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            vector<int> partialSum(m+1, 0);

            for(int i=0; i<mid; i++){
                int left = queries[i][0];
                int right = queries[i][1];
                int val = queries[i][2];

                partialSum[left] += val;
                partialSum[right+1] += (-val);
            }
            for(int i=1; i<m; i++){
                partialSum[i] = partialSum[i] + partialSum[i-1];
            }
            bool zeroArray = true;
            for(int i=0; i<m; i++){
                int numEle = nums[i];
                int decEle = partialSum[i];
                if(numEle > decEle){
                    zeroArray = false;
                    break;
                }
            }
            if(!zeroArray){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};