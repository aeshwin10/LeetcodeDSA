class Solution {
public:
    vector<vector<int>> graph;
    vector<int> parents, depth;

    void dfs(int currNode, int parent, int d){
        depth[currNode] = d;
        parents[currNode] = parent;
        for(int neighbour : graph[currNode]){
            if(neighbour!=parent){
                dfs(neighbour, currNode, d+1);
            }
        }
    }

    void dfs2(int currNode, int parent, vector<int>& amount, int& ans, int& tempSum){
        bool isLeaf = true;
        tempSum += amount[currNode];
        for(int neighbour : graph[currNode]){
            if(neighbour != parent){
                isLeaf = false;
                dfs2(neighbour, currNode, amount, ans, tempSum);
                
            } 
        }
        if(isLeaf){
            ans = max(ans, tempSum);
        }

        tempSum-=amount[currNode];
    }



    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        graph.resize(n);
        parents.resize(n, -1);
        depth.resize(n);

        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

        }

        dfs(0, -1, 0); //startNode, parent, depth

        int curr = bob, bobDepth = 0;
        while(curr!= -1){
            if(depth[curr]>bobDepth){
                amount[curr] = 0;
            }
            else if(depth[curr]==bobDepth){
                amount[curr] /= 2;
            }
            bobDepth++;
            curr = parents[curr];
        }

        int ans = INT_MIN;
        int tempSum = 0;
        dfs2(0, -1, amount, ans, tempSum);
        return ans;
    }
};