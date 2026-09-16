class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans="";
        for(string& it: strs){
            ans+=to_string(it.size());
            ans+=",";
        }
        ans+="#";
        for(string& it: strs)
            ans+=it;
        // cout << ans;
        return ans;

    }

    vector<string> decode(string s) {
        // ["Hello","World"]
        // 5,5,#HelloWorld

        if (s.empty()) return {};

        int n = s.size(), idx = -1;
        if(n == 0)return {};
        for(int i = 0; i < n; ++i){
            char ch = s[i];

            if(ch == '#') {
                idx = i;
                break;
            }

        }

        vector<string> sizes;
        string len;
        for(int i = 0; i < idx  ;++i) {
            cout << s[i] << endl;
            if(s[i] != ',')
                len.push_back(s[i]);
            else {
                sizes.push_back(len);
                len = "";
            }

        }

        // cout << endl;
        // for(auto it: sizes)cout << it << endl;
        // cout << endl;


        vector<string> ans;
        int i = idx + 1;
        for(int j = 0; j < sizes.size(); j++) {
            int sz = stoi(sizes[j]);

            ans.push_back(s.substr(i,sz));
            i+=sz;
        }
        return ans;
    }
};
