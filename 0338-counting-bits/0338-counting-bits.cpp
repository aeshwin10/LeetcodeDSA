class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count = 0;

        for(int i = 0; i<=n; i++){
            int ele = i;
            while(ele){
                count++;
                ele=(ele&(ele-1));
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};