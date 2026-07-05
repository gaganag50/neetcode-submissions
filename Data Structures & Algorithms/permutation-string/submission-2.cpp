class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int len = n;
        string A = s1;
        sort(A.begin(), A.end());
        for(int i = 0, j = i + len - 1; j < m; ++i, ++j) {
            string B = s2.substr(i, len);
            sort(B.begin(), B.end());
            if(A == B) return true;
        }
        return false;
    }
};
