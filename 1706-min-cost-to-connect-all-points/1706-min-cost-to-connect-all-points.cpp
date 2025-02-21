class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n);
        int totalWeight = 0;
        int connected = 1;
        int i = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //weight, node

        while(connected < n){
            visited[i] = 1;
            for(int j=0; j<n; j++){
                if(!visited[j]){
                    int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]- points[j][1]);
                    pq.push({dist, j});
                }
            }
            while(visited[pq.top().second]){
                pq.pop();
            }
            pair<int,int> nodeWithSmallestDist = pq.top();
            pq.pop();
            totalWeight+= nodeWithSmallestDist.first;
            i = nodeWithSmallestDist.second;
            connected++;
        }
        return totalWeight;
    }
};