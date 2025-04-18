class Solution {
public:
    void RLE(string& s, int n, int curN){
        if(curN==n){
            return;
        }
        string newString = "";
        char curLetter = s[0];
        int curCount = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i]==curLetter) curCount++;
            else{
                newString+= to_string(curCount);
                newString+= curLetter;
                curCount = 1;
                curLetter = s[i];
            }
        }
        newString+= to_string(curCount);
        newString+= curLetter;
        s = newString;
        return RLE(s, n, curN+1);
    }

    string countAndSay(int n) {
        string ans = "1";
        RLE(ans, n, 1);
        return ans;
    }
};