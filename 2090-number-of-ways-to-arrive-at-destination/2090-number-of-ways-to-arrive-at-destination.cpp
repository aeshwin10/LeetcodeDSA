class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = (1e9 + 7);
        vector<pair<long,long>> adj[n];
        vector<long long int> timee(n,1e18), ways(n,0);

        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //{time,node}
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        timee[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            int node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                long long t = it.second;
                if(t+time<timee[it.first]){
                    timee[it.first] = t+time;
                    pq.push({t+time,it.first});
                    ways[it.first]=ways[node];
                    }
                else if(t+time==timee[it.first]){
                    //pq.push({t+time,it.first});
                    ways[it.first]+=ways[node] % mod; 
                }
            }
        }
        
        return ways[n-1] % mod;
    }
};