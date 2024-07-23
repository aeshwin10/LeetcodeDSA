class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int row  = pq.top().second.first;
            int col = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            if(row == n-1 && col == m-1){
                return effort;
            }

            for(int i=0; i<4; i++){
                int newRow = row+drow[i];
                int newCol = col+dcol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && 
                dist[newRow][newCol] > max(effort,abs(heights[row][col]-heights[newRow][newCol]))){
                    dist[newRow][newCol] = max(effort,abs(heights[row][col]-heights[newRow][newCol]));
                    pq.push({dist[newRow][newCol],{newRow,newCol}});
                }
            }

        }
        return dist[n-1][m-1];

    }
};