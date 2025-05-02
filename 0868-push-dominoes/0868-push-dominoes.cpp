class Solution {
public:
    void search(char c, int pos, int val, string& dominoes, vector<pair<char,int>>& ans){
        if(dominoes[pos]=='L' || dominoes[pos]=='R'){
            return;
        }
        if(val < ans[pos].second){
            ans[pos].first = c;
            ans[pos].second = val;

            if(pos-1!=-1 && c=='L'){
                search(c, pos-1, val+1, dominoes, ans);
            }
            else if(pos+1!=ans.size() && c =='R'){
                search(c, pos+1, val+1, dominoes, ans);
            }
        }
        else if(val==ans[pos].second){
            ans[pos].first = '.';
            ans[pos].second = val;
        }
    }

    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<pair<char,int>> ans;
        for(auto& c : dominoes){
            ans.push_back({c,INT_MAX});
        }
        queue<pair<char,int>> q;
        for(int i=0; i<n; i++){
            char c = dominoes[i];
            if(c=='L' || c=='R'){
                q.push({c,i});
            }
        }
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            if(ele.second!=0 && ele.first=='L'){
                search(ele.first, ele.second-1, 0+1, dominoes, ans);
            }
            if(ele.second!=n-1 && ele.first == 'R'){
                search(ele.first, ele.second+1, 0+1, dominoes, ans);
            }
        }
        string s = "";
        for(int i=0; i<n; i++){
        char curChar = ans[i].first;
        s+=curChar;
        }
        return s;
    }
    
};