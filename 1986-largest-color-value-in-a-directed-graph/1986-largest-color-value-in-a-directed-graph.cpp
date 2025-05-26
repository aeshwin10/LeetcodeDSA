class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> colorCount(n, vector<int>(26, 0));

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
            colorCount[i][colors[i]-'a'] = 1;
        }

        int visited = 0;
        int result = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            visited++;

            for(int v : adj[u]){
                for(int c = 0; c<26; c++){
                    int val = colorCount[u][c] + (colors[v] - 'a' == c ? 1 : 0);
                    colorCount[v][c] = max(colorCount[v][c], val);
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }

            result = max(result, *max_element(colorCount[u].begin(), colorCount[u].end()));
        }

        return visited == n ? result : -1;
    }
};