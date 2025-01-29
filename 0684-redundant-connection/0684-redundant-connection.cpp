class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu==pv) return;
        if(size[pu]>size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(auto it : edges){
                if(ds.findUParent(it[0])==ds.findUParent(it[1])){
                    return {it[0], it[1]};
                }
                else{
                    ds.unionBySize(it[0], it[1]);
                }
            }
        }
        return {};
    }   
};