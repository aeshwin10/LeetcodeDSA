class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> products;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]!=nums[j]){
                    int product = nums[i]*nums[j];
                    products[product]++;
                }
            }
        }

        for(auto &it : products){
            int c = it.second;
            if(c>1){
                ans+= (8*((c*(c-1))/2));
            }
        }

        return ans;

    }
};