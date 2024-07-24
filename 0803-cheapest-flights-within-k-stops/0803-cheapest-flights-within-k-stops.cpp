class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});  //{stops,{node,cost}}
        vector<int> costs(n,1e9);
        costs[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k){
                continue;
            }
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edw = iter.second;

                if(cost + edw < costs[adjNode]){
                    costs[adjNode] = cost + edw;
                    q.push({stops+1,{adjNode,cost + edw}});
                }
            }
        }

        
        if(costs[dst]==1e9){
            return -1;
        }
        return costs[dst];

    }
};