class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int> ans(n+1);
        int low=0;
        int high=n;
        for(int i=0; i<n; i++){
            if(s[i]=='I'){
                ans[i] = low;
                low++;
            }
            else if(s[i]=='D'){
                ans[i] = high;
                high--;
            }
        }
        ans[n] = low;
        return ans;
    }
};