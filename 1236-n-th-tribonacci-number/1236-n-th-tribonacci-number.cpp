class Solution {
public:
    int calculate(int x, vector<int>& dp){
        if(x==1 || x==0){
            return x;
        }
        if(x<0){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        
        return (dp[x] = (calculate(x-1, dp) + calculate(x-2, dp) + calculate(x-3, dp)));
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return (calculate(n, dp));
    }
};