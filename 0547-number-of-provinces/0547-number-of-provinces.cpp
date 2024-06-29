class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int vertices = isConnected.size();
        vector<int> visited(vertices+1,0);

        for(int city=1; city<=vertices; city++){
            if(!visited[city]){
                provinces++;
                visited[city] = 1;
                dfs(city, visited, isConnected);
            }
        }
        return provinces;
    }
    void dfs(int city, vector<int>& visited, vector<vector<int>> isConnected){
        for(int i=0; i<isConnected[city-1].size(); i++){
            if(isConnected[city-1][i] && visited[i+1]==0){
                visited[i+1] = 1;
                dfs(i+1,visited, isConnected);
            }
        }
    }
};