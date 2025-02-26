class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        long long ans1 = 0;
        long long ans2 = 0;

        long long temp1 = 0;
        long long temp2 = 0;
        for(int i=0; i<n; i++){
            temp1+=nums[i];
            temp2+=nums[i];
            ans1 = max(temp1, ans1);
            
            if(temp1<=0){
                temp1 = 0;
            }

            ans2 = min(ans2, temp2);
            if(temp2>=0){
                temp2 = 0;
            }
        }
        long long finalAns = max(ans1, abs(ans2));
        return finalAns;
    }
};