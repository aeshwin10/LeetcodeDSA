class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = groups.size();

        int prevGrp = groups[0];
        ans.push_back(words[0]);
        for(int i=1; i<n; i++){
            int curGrp = groups[i];
            if(curGrp!=prevGrp){
                ans.push_back(words[i]);
                prevGrp^=1;
            }
        }
        return ans;
    }
};