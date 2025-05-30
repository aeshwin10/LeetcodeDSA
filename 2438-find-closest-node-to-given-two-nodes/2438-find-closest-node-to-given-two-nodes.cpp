class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, int lvl, vector<int>& visited){
        visited[node] = 1;
        dist[node] = lvl;
        int neighbour = edges[node];
        if(neighbour!=-1 && !visited[neighbour]){
            dfs(neighbour, edges, dist, lvl+1, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        vector<int> visited1(n, 0), visited2(n, 0);
        
        dfs(node1, edges, dist1, 0, visited1);
        dfs(node2, edges, dist2, 0, visited2);

        int minDist = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int curDist = max(dist1[i], dist2[i]);
                if(curDist < minDist){
                    minDist = curDist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};