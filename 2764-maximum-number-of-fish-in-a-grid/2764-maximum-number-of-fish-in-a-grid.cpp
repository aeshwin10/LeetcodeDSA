class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& visited, int& tempSum, vector<vector<int>>& grid, int& m, int& n){
        visited[r][c] = 1;
        tempSum+=grid[r][c];
        for(int i=0; i<4; i++){
            int newR = r+dx[i];
            int newC = c+dy[i];
            if(newR>=0 && newR<m && newC>=0 && newC<n && !visited[newR][newC]){
                dfs(newR, newC, visited, tempSum, grid, m, n);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    visited[i][j] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    int tempSum = 0;
                    dfs(i, j, visited, tempSum, grid, m, n);
                    ans = max(ans, tempSum);
                    tempSum = 0;
                }
            }
        }

        return ans;
    }
};