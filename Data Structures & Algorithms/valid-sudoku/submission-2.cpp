class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        const int N = 9;
        for(int i = 0; i < N; ++i) {
            set<int> doesExist;
            for(int j = 0; j < N; ++j){
                
                char it = a[i][j];
                if(it != '.') {
                    if(doesExist.count(it))return false;
                    doesExist.insert(it);
                }
            }
        }

        for(int j = 0; j < N; ++j) {
            set<int> doesExist;
            for(int i = 0; i < N; ++i){
                
                char it = a[i][j];
                if(it != '.') {
                    if(doesExist.count(it))return false;
                    doesExist.insert(it);
                }
            }
        }

        // 0,0  0,3    0,6
        // 3,0  3,3,   3,6

        for(int boxRow = 0; boxRow < 3; ++boxRow) {
            int st_i = boxRow * 3;
            for(int boxCol = 0; boxCol < 3; ++boxCol) {
                int st_y = boxCol * 3;
                set<int> doesExist;
                for(int i = st_i; i < st_i + 3; ++i) {
                    for(int j = st_y; j < st_y + 3; ++j) {
                        
                        char it = a[i][j];
                        if(it != '.') {
                            if(doesExist.count(it))return false;
                            doesExist.insert(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
