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

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row=0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col]==0) continue;
                for(int i =0; i<4; i++){
                    int newRow = row + drow[i];
                    int newCol = col + dcol[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]){
                        int nodeNo = row*n + col;
                        int newNodeNo = newRow*n + newCol;
                        ds.unionBySize(nodeNo, newNodeNo);
                    }
                }   
            }
        }

        int finalAns = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]==0){
                    set<int> components;
                    for(int i=0; i<4; i++){
                        int newRow = row + drow[i];
                        int newCol = col + dcol[i];
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]){
                            if(grid[newRow][newCol] == 1){
                                components.insert(ds.findUParent(newRow * n + newCol));
                            }
                        }
                    }
                    int sizeTotal = 0;
                    for(auto it : components){
                        sizeTotal+=ds.size[it];
                    }
                    finalAns = max(finalAns, sizeTotal + 1);   
                }
            }
        }
        for(int cell=0; cell<n*n; cell++){
            finalAns = max(finalAns, ds.size[ds.findUParent(cell)]);
        }
        return finalAns;
    }
};