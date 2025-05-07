class Solution {
public:
    bool check(int row, int col,int n, int m){
        if(row>=0 && row<=n-1 && col>=0 && col<=m-1) return true;
        return false;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0,0}});

        while(!q.empty()){
            int t = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(t > dist[row][col]) continue;

            if(row==n-1 && col==m-1) return t;

            int drow[4] = {0, -1, 0, 1};
            int dcol[4] = {-1, 0, 1, 0};

            for(int i=0; i<4; i++){
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if(check(newRow, newCol, n, m)){
                    int diff = max(t, moveTime[newRow][newCol]) + 1;
                    if(diff < dist[newRow][newCol]){
                        dist[newRow][newCol] = diff;
                        q.push({diff, {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};