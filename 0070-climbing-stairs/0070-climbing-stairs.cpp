class Solution {
public:
    int Vishal(int n, vector<int>& dp){
        if(n==1 || n==0){
            return dp[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = Vishal(n-1, dp) + Vishal(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {  
        vector<int> dp(n+1, -1);
        if(n==1){
            return 1;
        }
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return Vishal(n, dp);
    }
};