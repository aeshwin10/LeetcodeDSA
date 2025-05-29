class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, vector<bool>* included = nullptr){
        queue<int> q;
        vector<int> visited(adj.size(), 0);
        int evenCnt = 0;
        q.push(node);
        visited[node] = 1;
        bool even = true;
        while(!q.empty()){
            int sz = q.size();
            if(even){
                evenCnt+=sz;
                even = false;
            }
            else{
                even = true;
            }
            
            for(int i=0; i<sz; i++){
                int u = q.front();
                q.pop();
                if(included && !even){
                    (*included)[u] = true;
                }
                for(auto nei : adj[u]){
                    if(!visited[nei]){
                        q.push(nei);
                        visited[nei] = 1;
                    }
                }
            }  
        }
        return evenCnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1+1), adj2(n2+1);

        for(auto &edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto &edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int evenCnt = bfs(0, adj2);
        int oddCnt = n2 - evenCnt;
        int bestCnt = max(evenCnt, oddCnt);

        vector<bool> bestNodesArr(n1, false);
        int evenCnt1 = bfs(0, adj1, &bestNodesArr);

        vector<int> ans(n1);
        for(int i=0; i<n1; i++){
            if(bestNodesArr[i]){
                ans[i] = evenCnt1 + bestCnt;
            }
            else{
                ans[i] = (n1 - evenCnt1) + bestCnt;
            }
        }
        return ans;
    }
};