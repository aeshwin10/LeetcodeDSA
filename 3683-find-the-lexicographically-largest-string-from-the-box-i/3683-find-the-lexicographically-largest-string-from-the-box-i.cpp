class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        int k = n-numFriends+1;
        string ans = "";
        
        for(int i=0; i<word.size(); i++){
            ans = max(ans, word.substr(i, k));
        }
        
        return ans;
    }
};