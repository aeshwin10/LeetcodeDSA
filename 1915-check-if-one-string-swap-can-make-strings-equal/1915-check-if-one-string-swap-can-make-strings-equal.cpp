class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cntDiff = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2){
            return false;
        }
        for(int i=0; i<n1; i++){
            if(s1[i]!=s2[i]){
                cntDiff++;
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if((cntDiff==2 || cntDiff==0) && s1==s2) return true;
        return false;
    }
};