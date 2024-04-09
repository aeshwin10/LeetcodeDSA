class Solution {
public:
    int lengthOfLastWord(string s) {
        int countt=0;
        bool initial=true;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                initial=false;
                countt++;
            }
            else if(s[i]==' '){
                if (initial==false){
                    return countt;
                }
            }
        }
        return countt;
    }  
};