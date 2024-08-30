class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<n; i++){
            if(!obstacleGrid[0][i]){
                dp[0][i] = 1;
            }
            else{
                break;
            }
        }
        for(int i=0; i<m; i++){
            if(!obstacleGrid[i][0]){
                dp[i][0] = 1;
            }
            else{
                break;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(!obstacleGrid[j][i]){
                    dp[j][i] = dp[j-1][i] + dp[j][i-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};