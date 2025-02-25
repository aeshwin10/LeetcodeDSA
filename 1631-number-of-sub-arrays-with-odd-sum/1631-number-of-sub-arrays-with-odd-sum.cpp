class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int evenSum = 1;
        int oddSum = 0;
        int ans = 0;
        int tempSum = 0;

        for(auto& i : arr){
            tempSum += (i%2);
            if(tempSum&1){
                ans = (ans + evenSum) % MOD;
                oddSum++;
            }
            else{
                ans = (ans + oddSum) % MOD;
                evenSum++;
            }
        }
        return ans;
    }
};