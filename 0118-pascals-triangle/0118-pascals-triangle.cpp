class Solution {
public:
    vector<int> genRow(int row){
        long long ans=1;
        vector<int> curRow;
        curRow.push_back(ans);
        for(int col = 1; col<row; col++){
            ans = ans*(row-col);
            ans = ans/col;
            curRow.push_back(ans);
        }
        return curRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1; i<=numRows; i++){
            result.push_back(genRow(i));
        }
    return result;
    }
};