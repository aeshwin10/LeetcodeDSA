class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            visited[row][col] = 1;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>0 && nrow < n-1 && ncol>0 && ncol<m-1 && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    } 
};