class Solution {
    int replacements(vector<int>& freq){
        int total = 0, M = 0;
        for(int i = 0; i < 26; ++i) {
            M = max(M, freq[i]);
            total += freq[i];
        }
        return total - M;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int n = s.size(), ans = 0;
        for(int L = 0, R = 0; R < n; ++R) {
            char ch = s[R];
            int idx = ch-'A';
            freq[idx]++;
            while(L < R && replacements(freq) > k) {
                freq[s[L]-'A']--;
                L++;
            }
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};
