class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        int n = nums.size();
        vector<int> prefix_sum(n);

        sort(nums.begin(),nums.end());

        prefix_sum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        
        for(int i=0; i<m; i++){
            int q = queries[i];
            int low = 0;
            int high = n-1;
            bool flag = true;
            while(low<=high){
                int mid = (low+high)/2;
                
                if(prefix_sum[mid]==q){
                    ans[i] = mid+1;
                    flag = false;
                    break;
                }
                if(prefix_sum[mid]<q){
                    low=mid+1;
                }
                if(prefix_sum[mid]>q){
                    high = mid-1;
                }
            }
            if(flag){
                ans[i]=low;
            }
        }
        return ans;
    }
};