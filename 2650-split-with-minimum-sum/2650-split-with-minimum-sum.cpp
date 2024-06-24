class Solution {
public:
    int splitNum(int num) {
        string a,b,s=to_string(num);
        sort(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            if(i%2==1){
                a.push_back(s[i]);
            }
            else{
                b.push_back(s[i]);
            }
        }
        return stoll(a)+stoll(b);
    }
};