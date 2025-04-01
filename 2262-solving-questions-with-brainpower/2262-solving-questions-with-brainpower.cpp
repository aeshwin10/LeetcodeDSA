class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0ll);
        dp[n-1] = questions[n-1][0];

        for(int i=n-2; i>=0; i--){
            int lookAfter = i+questions[i][1]+1;
            if(lookAfter <= n-1){
                dp[i] = max((long long)dp[i+1], (long long)questions[i][0]+dp[lookAfter]);
            }
            else{
                dp[i] = max((long long)dp[i+1], (long long)questions[i][0]);
            }
        }
        return dp[0];
    }
};