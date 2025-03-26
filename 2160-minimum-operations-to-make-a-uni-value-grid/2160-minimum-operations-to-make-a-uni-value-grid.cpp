class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int val = (grid[0][0] % x);
        vector<int> arr;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr.push_back(grid[i][j]);
                if((grid[i][j]%x)!=val){
                    return -1;
                }
            }
        }
        sort(arr.begin(), arr.end());
        int target = arr[m*n/2];
        int ans = 0;
        for(int i=0; i<m*n; i++){
            ans+= (abs(target-arr[i]) / x);
        }
        return ans;

    }
};