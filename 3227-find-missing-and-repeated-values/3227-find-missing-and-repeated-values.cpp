class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr(n*n, 0);
        
        int a;
        int b;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[grid[i][j] - 1]++;
                if(arr[grid[i][j]-1]==2){
                    a = grid[i][j];
                }
            }
        }

        for(int i=0; i<n*n; i++){
            if(arr[i]==0){
                b=(i+1);
                break;
            }
        }

        vector<int> temp = {a,b};
        return temp;
    }
};