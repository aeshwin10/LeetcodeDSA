class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int q = queries.size();
        unordered_map<int,int> mp1;    // <ball, color>
        unordered_map<int,int> mp2; //  <color, count>
        int distinct = 0;
        for(int i=0; i<q; i++){
            int pos = queries[i][0];
            int col = queries[i][1];

            if(mp1[pos]>0){
                mp2[mp1[pos]]--;
                if(mp2[mp1[pos]]==0){
                    mp2.erase(mp1[pos]);
                    distinct--;
                }
            }
            mp1[pos] = col;
            mp2[col]++;
            if(mp2[col]==1){
                distinct++;
            }
            ans.push_back(distinct);
        }
        return ans;
    }
};