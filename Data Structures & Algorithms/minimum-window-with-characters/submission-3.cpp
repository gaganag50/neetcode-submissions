class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> freq_s(126), freq_t(126);
        for(char ch: t){
            freq_t[ch]++;
        }
        int matches_found = 0;
        int l = -1, r, len;
        for(int L = 0, R = 0; R < n; ++R) {
            char ch = s[R];
            freq_s[ch]++;
            if(freq_s[ch] <= freq_t[ch]) {
                matches_found++;
            }
            while(matches_found == m) {
                ch = s[L];
                if(freq_s[ch] > freq_t[ch]) {
                    freq_s[ch]--;
                    L++;
                } else {
                    int currLen = R - L + 1;
                    if(l == -1 || currLen < len) {
                        l = L;
                        r = R;
                        len = currLen;
                    }
                    break;
                }
            }
        }
        if(l == -1)return "";
        len = r - l + 1;
        return s.substr(l,len);
    }
};
