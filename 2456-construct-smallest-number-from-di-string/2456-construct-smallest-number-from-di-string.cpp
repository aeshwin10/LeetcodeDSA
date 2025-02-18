class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        int num = 1;
        stack<int> s;

        for(int i=0; i<=n; i++){
            s.push(num++);
            if(i==n || pattern[i]=='I'){
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        
        return ans;
    }
};