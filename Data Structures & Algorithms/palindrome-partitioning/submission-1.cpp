class Solution {
    vector<vector<string>> ans;
    vector<string> curr;
    bool is_pal(const string& s){
        int n = s.size();
        for(int i = 0, j = n - 1; i < j; ++i,--j){
            if(s[i]!=s[j])return false;
        }
        return true;
    }
    void helper(const string& s, int start, int end) {
        if(start > end){
            ans.push_back(curr);
            return;
        }
        string temp;
        for(int i = start; i <= end; ++i) {
            temp.push_back(s[i]);
            if(is_pal(temp)){
                curr.push_back(temp);
                helper(s,i+1,end);
                curr.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        ans.clear();
        curr.clear();
        int n = s.size();
        helper(s,0,n-1);
        return ans;
    }
};
