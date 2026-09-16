class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size(), ans = 0;
        for(int L = 0, R = 0; R < n; ++R) {
            char ch = s[R];
            if(set.count(ch)) {
                while(set.count(ch)) {
                    set.erase(s[L++]);
                }
            }
            set.insert(ch);

            ans = max(ans, (int)set.size());
        }
        return ans;
    }
};
