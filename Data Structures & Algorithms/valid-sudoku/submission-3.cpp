class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9], col[9][9], boxes[9][9];
        
        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] == '.')continue;
                int val = board[r][c]-'0';
                int box = 3 * (r/3) + (c/3);
                if(row[val - 1][r] || col[val - 1][c] || boxes[val - 1][box]) {return false;}
                row[val - 1][r] = true;
                col[val - 1][c] = true;
                boxes[val - 1][box] = true;
            }
        }
        return true;
    }
};
