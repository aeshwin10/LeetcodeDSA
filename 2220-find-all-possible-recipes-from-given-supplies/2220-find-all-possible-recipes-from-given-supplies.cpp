class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       unordered_map<string,vector<string>> graph;
        int n = recipes.size();
        unordered_set<string> s;
        for(auto x : supplies) s.insert(x);            
		
        unordered_map<string,int> indegree;   
        for(auto x : recipes)indegree[x] = 0;                      
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)ingredients[i].size(); j++){
                if(s.find(ingredients[i][j]) == s.end()){     
                    graph[ingredients[i][j]].push_back(recipes[i]);    
                    indegree[recipes[i]]++;                    
                }
            }
        }
        
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto nbr : graph[tmp]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
};