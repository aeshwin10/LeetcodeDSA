class NumMatrix {
private:
    int row, col;
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        preSum = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                preSum[i][j] = matrix[i-1][j-1] + preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */