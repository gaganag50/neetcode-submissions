class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int sz = n * m;
        int lo = 0, hi = sz-1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int r = mid/m;
            int c = mid%m;
            if(matrix[r][c] == target)return true;
            else if(matrix[r][c] < target)lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};
