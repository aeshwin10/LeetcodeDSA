class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = i * j;
                if((temp%k)==0 && nums[i]==nums[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};