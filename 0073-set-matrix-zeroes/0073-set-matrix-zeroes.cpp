class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rowFalse(n, 0);
        vector<int> colFalse(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    rowFalse[i]=1;
                    colFalse[j]=1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rowFalse[i] || colFalse[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};