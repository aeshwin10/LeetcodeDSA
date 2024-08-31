class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0] = grid[0][0];
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[j][i] = grid[j][i] + min(dp[j-1][i], dp[j][i-1]);
            }
        }
        return dp[m-1][n-1];

        
    }
};