const int mod = 1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        vector<long long> dist(n, LLONG_MAX);

        for(auto &i : roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> ways(n, 0);
        
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [curDist, node] = pq.top();
            pq.pop();

            if(curDist > dist[node]) continue;

            for(auto& [neighbour, weight] : adj[node]){
                long long newDist = curDist + weight;
                if(newDist < dist[neighbour]){
                    dist[neighbour] = newDist;
                    ways[neighbour] = ways[node];
                    pq.push({newDist, neighbour});
                }
                else if(newDist == dist[neighbour]){
                    ways[neighbour] = (ways[neighbour] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};