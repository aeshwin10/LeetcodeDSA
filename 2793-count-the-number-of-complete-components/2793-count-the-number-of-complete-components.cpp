class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& mp, int& edgeCount, vector<int>& visited, int& nodesVisited){
        visited[node] = 1;
        edgeCount+= mp[node].size();
        nodesVisited++;

        for(auto neighbour : mp[node]){
            if(!visited[neighbour]){
                dfs(neighbour, mp, edgeCount, visited, nodesVisited);
            }
        }
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto &it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int ans = 0;
        vector<int> visited(n, 0);
        for(int key=0; key<n; key++){
            if(!visited[key]){
                int edgeCount = 0;
                int nodesVisited = 0;
                dfs(key, mp, edgeCount, visited, nodesVisited);
                if(((long long)nodesVisited * (nodesVisited-1))==(long long)edgeCount){
                    ans++;
                }
            }
        }
        return ans;
    }
};