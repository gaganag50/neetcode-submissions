class Solution {
    const int N = 26;
    int calculateDelta(const vector<int>& freq) {
        int total = 0, M = 0;
        for(auto& f: freq){
            total += f;
            M = max(M, f);
        }
        return total - M;
    }
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(N);
        int n = s.size(), ans = 0;
        for(int L = 0, R = 0; R < n; ++R) {
            char ch = s[R];
            freq[ch-'A']++;
            
            while(calculateDelta(freq) > k) {
                freq[s[L++]-'A']--;
            }
            
            ans = max(ans, R-L+1);
        }
        return ans;
    }
};
