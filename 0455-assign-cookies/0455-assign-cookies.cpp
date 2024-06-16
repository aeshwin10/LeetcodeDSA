class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookies = s.size();
        if(cookies == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0;
        int j=0;
        

        while(j<cookies && i<g.size()){
            if(g[i]<=s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
};