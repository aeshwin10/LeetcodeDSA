class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int l = n-1;
        /*
        while(nums[i]<0){
            i++;
            if(i>k-2){
                return ans;
            }
        }
        while(nums[k]>n){
            k--;
            if(k<i+2){
                return ans;
            }
        }
        */
        
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            else{
                for(int j=i+1;j<n;j++){
                    if((j!=i+1) && nums[j]==nums[j-1]) continue;    
                    else{
                        int k = j+1;
                        int l = n-1;
                        while(k<l){
                            long long summ =0;
                            summ+= nums[i];
                            summ+= nums[j];
                            summ+= nums[k];
                            summ+= nums[l];
                            if(summ>target){
                                l--;
                            }
                            else if(summ<target){
                                k++;
                            }
                            else{
                                vector<int> temp;
                                temp.push_back(nums[i]);
                                temp.push_back(nums[j]);
                                temp.push_back(nums[k]);
                                temp.push_back(nums[l]);
                                ans.push_back(temp);
                                k++;
                                l--;
                                while(k<l && nums[k]==nums[k-1]) k++;
                                while(k<l && nums[l]==nums[l+1]) l--;
                            }
                        }
                    }
                } 
            }
        }
        return ans;
    }
};