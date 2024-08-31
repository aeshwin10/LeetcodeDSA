class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp;
        dp.push_back(triangle[0][0]);

        for(int i=1; i<n; i++){
            vector<int> temp;
            for(int j=0; j<i+1; j++){
                if(j==0){
                    temp.push_back(triangle[i][j]+dp[0]);
                }
                else if(j==(i)){
                    temp.push_back(triangle[i][j]+dp[j-1]);
                }
                else{
                    temp.push_back(triangle[i][j] + min(dp[j-1], dp[j]));
                }
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for(int i=0; i<dp.size(); i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};