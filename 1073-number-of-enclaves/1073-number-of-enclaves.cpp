class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && (i==0 || j==0 || i==n-1 || j==m-1)){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>0 && ncol > 0 && nrow < n-1 && ncol < m-1 && visited[nrow][ncol]==0 && grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && grid[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};