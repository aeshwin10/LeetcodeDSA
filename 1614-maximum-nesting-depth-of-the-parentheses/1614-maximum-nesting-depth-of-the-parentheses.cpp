class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;

        for(auto i: s){
            if(i=='('){
                st.push(i);
            }
            else if(i==')'){
                    st.pop();
            }
            maxi=max(maxi,(int)st.size());
        }
        return maxi;
    }
};