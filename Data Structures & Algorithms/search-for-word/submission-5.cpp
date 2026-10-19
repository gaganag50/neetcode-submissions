class Solution {
    int n,m;
    using pi = pair<int,int> ;
    set<pi> vis;
    bool is_inside(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    bool is_possible(vector<vector<char>>& board, int i, int j, int pos, string& word){
        if(pos == word.size()-1)return true;
        vis.insert({i,j});

        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0}; 

        for(int dir = 0; dir < 4; ++dir){
            if(is_inside(i+dx[dir], j + dy[dir]) && word[pos+1] == board[i+dx[dir]][j + dy[dir]] && !vis.count({i+dx[dir],j + dy[dir]}))
                if(is_possible(board, i+dx[dir], j + dy[dir], pos + 1, word))return true;
        }
        vis.erase({i,j});
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j){
                if(board[i][j] == word[0]) {

                    if(is_possible(board,i,j,0,word))return true;
                }
            }
        }
        return false;
    }
};
