class UnionFind{
    private: vector<int> parents, rank;
    public:
        vector<int> weights;
        UnionFind(int n){
            rank.assign(n, 0);
            parents.assign(n, 0);
            iota(parents.begin(), parents.end(), 0);
            weights.resize(n+1, INT_MAX);
        }
        int findSet(int u){
            if(parents[u]==u){
                return u;
            }
            return parents[u] = findSet(parents[u]);
        }
        int isSameSet(int u, int v){
            return findSet(u) == findSet(v);
        }
        void unionSet(int u, int v, int wt){
            int x = findSet(u);
            int y = findSet(v);
            weights[x] = weights[x] & wt & weights[y];
            weights[y] = weights[y] & wt & weights[x];
            if(!isSameSet(u, v)){
                if(rank[x]>rank[y]){
                    parents[y] = x;
                }
                else{
                    parents[x] = y;
                    if(rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind dsu(n);
        for(auto it: edges){
            dsu.unionSet(it[0], it[1], it[2]);
        }
        vector<int> ans;
        for(auto it: query){
            if(it[0]==it[1]){
                ans.push_back(0);
                continue;
            }
            int p1 = dsu.findSet(it[0]);
            int p2 = dsu.findSet(it[1]);
            if(p1==p2){
                int val = dsu.weights[p1];
                if(val == INT_MAX) val = 0;
                ans.push_back(val);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};