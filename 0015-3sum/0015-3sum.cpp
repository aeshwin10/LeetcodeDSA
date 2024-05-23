class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int i=0;
        while(i<n){
            if(i!=0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            else{
                int j = i+1;
                int k = n-1;
                while(j<k){
                    int tempSum = nums[i]+nums[j]+nums[k];
                    if(tempSum>0){
                        k=k-1;
                    }
                    else if(tempSum<0){
                        j+=1;
                    }
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;
                        

                    }
                }
                i++;
                continue;
            } 
        }
        return ans;
    }        
};