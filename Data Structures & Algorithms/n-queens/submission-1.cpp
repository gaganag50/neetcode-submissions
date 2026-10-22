class Solution {
    vector<vector<string>> ans;
    bool can_place(int n, int row, int col, vector<string>& curr) {
        for(int i = 0; i < row; ++i){
            if(curr[i][col]=='Q')return false;
            if(col-1-i>=0 && curr[row-1-i][col-1-i]=='Q')return false;
            if(col+1+i < n && curr[row-1-i][col+1+i]=='Q')return false;
        }
        return true;
        
    }
    void solve(int n, int row, vector<string>& curr){
        if(row == n){
            ans.push_back(curr);
            return ;
        }
        for(int col = 0; col < n; ++col) {
            if(can_place(n,row,col,curr)){
                curr[row][col]='Q';
                solve(n, row + 1, curr);
                curr[row][col]='.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> curr(n,string (n,'.'));
        solve(n,0,curr);
        return ans;

    }
};
