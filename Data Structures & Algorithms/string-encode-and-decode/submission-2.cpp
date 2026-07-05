class Solution {
public:
    void encode_helper(vector<string>& strs, int& idx, int n, string& ans) {
        if(idx == n)return;
        ans += strs[idx] + "\n";
        idx++;
        encode_helper(strs, idx, n, ans);
    }
    string encode(vector<string>& strs) {
        string ans;
        int n = strs.size();
        int idx = 0;
        encode_helper(strs, idx, n, ans);

        return ans;
    }
    void decode_helper(string& s, int idx, int n, string &temp, vector<string>& ans){
        if(idx == n)return;
        char a = s[idx];
        if(a == '\n'){
            ans.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(a);
            
        }
        decode_helper(s, idx + 1, n, temp, ans);


    }
    vector<string> decode(string s) {
        vector<string> ans;

        int n = s.size();
        string temp;
        int idx = 0;
        decode_helper(s, idx, n, temp, ans);
        return ans;
    }
};
