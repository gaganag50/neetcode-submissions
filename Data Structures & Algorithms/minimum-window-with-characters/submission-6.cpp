class Solution {
    
public:
    string minWindow(string s, string t) {
        vector<int> freq1(128), freq2(128);
        for(char ch: t){
            freq2[ch]++;
        }
        int n = s.size(), m = t.size();
        if(n < m)return "";
        int ans = INT_MAX, l = -1;
        int char_matching = 0;
        for(int L = 0, R = 0; R < n; ++R) {
            char ch = s[R];
            freq1[ch]++;
            if(freq1[ch] <= freq2[ch])char_matching++;
            while(char_matching == m) {
                int curr = R - L + 1;
                if(ans > curr) {
                    ans = curr;
                    l = L;
                }

                freq1[s[L]]--;
                if(freq1[s[L]] < freq2[s[L]]) char_matching--;
                L++;
            }

        }
        if(l == -1) return "";

        return s.substr(l, ans);
    }
};
