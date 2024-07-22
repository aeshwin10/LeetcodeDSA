class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});

        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if((r==n-1) && (c == n-1)){
                return dis;
            }

            for(int i=0; i<8; i++){
                int newRow = r+dr[i];
                int newCol = c+dc[i];

                if(newRow>=0 && newCol>=0 && newRow<n && newCol<n && grid[newRow][newCol]==0 && (dis+1 < dist[newRow][newCol])){
                    dist[newRow][newCol] = dis+1;
                    
                    q.push({dis+1,{newRow,newCol}});
                }
            }

        }
        return -1;
    }
};