class Solution {
public:
    bool check(int row, int col, int n, int m){
        if(row>=0 && row<n && col>=0 && col<m) return true;
        return false;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        dp[0][0] = 0;
        pq.push({0, {0,0}});
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!pq.empty()){
            int curTime = pq.top().first;
            int curRow = pq.top().second.first;
            int curCol = pq.top().second.second;
            pq.pop();

            if(dp[curRow][curCol]<curTime) continue;
            if(curRow == n-1 && curCol == m-1){
                return curTime;
            }

            for(int i=0; i<4; i++){
                int newRow = curRow + drow[i];
                int newCol = curCol + dcol[i];
                if(check(newRow, newCol, n, m)){
                    bool add2 = true;
                    if((newRow + newCol)&1){
                        add2 = false;
                    }
                    int newTime = max(curTime, moveTime[newRow][newCol]) + 1;
                    if(add2) newTime+=1;
                    if(newTime < dp[newRow][newCol]){
                        dp[newRow][newCol] = newTime;
                        pq.push({dp[newRow][newCol],{newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};