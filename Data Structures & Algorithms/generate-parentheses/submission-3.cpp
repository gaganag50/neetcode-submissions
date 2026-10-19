class Solution {
    void helper(string& s, vector<string>& ans, int open, int close, int n){
        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            helper(s, ans, open + 1, close, n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            helper(s, ans, open, close + 1, n);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        helper(s,ans,0,0,n);
        return ans;
    }
};
