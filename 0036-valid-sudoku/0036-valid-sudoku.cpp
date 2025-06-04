class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(10, vector<int>(10, 0));
        vector<vector<int>> cols(10, vector<int>(10, 0));
        vector<vector<vector<int>>> blocks(4, vector<vector<int>>(4, vector<int>(10, 0)));

        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col]=='.') continue;
                int num = board[row][col]-'1';
                if(rows[row][num]++ || cols[col][num]++ || blocks[row/3][col/3][num]++) 
                    return false;
            }
        }
        return true;
    }
};