class Solution {
public:
    int balancedStringSplit(string s) {
        int i=0;
        int Lcount = 0;
        int Rcount = 0;
        int n = s.size();
        int ans = 0;
        while(i<n){
            if(s[i]=='L'){
                Lcount++;
            }
            else if(s[i]=='R'){
                Rcount++;
            }
            if(Lcount==Rcount){
                ans++;
                Lcount=0;
                Rcount=0;
            }
            i++;
        }
        return ans;
    }
};