class Solution {
public:
    int findMin(int x, vector<int>& dp, vector<int>& cost){
        if(dp[x]!=INT_MAX) return dp[x];
        return dp[x] = min(findMin(x-1, dp, cost)+cost[x-1], findMin(x-2, dp, cost)+cost[x-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        return findMin(n, dp, cost);
    }
};