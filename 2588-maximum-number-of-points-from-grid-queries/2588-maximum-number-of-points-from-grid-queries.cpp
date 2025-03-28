class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(queries.size());
        vector<pair<int,int>> sortedQueries;
        for(int i=0; i<queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;

        int topLeft = grid[0][0];
        pq.push({topLeft, {0,0}});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        int points = 0;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

        for(auto [qVal, qIdx] : sortedQueries){
            while(!pq.empty() && (pq.top().first<qVal)){
                auto [val, pos] = pq.top();
                pq.pop();
                int row = pos.first, col = pos.second;
                points++;

                for(auto& [dr, dc] : directions){
                    int nr = row+dr, nc = col+dc;
                    if(nr>=0 && nr < n && nc >=0 && nc < m && !visited[nr][nc]){
                        pq.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[qIdx] = points;
        }
        return ans;
    }
};