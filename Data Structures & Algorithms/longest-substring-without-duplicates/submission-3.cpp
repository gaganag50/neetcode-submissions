#include <cstring>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = 256;
        int freq[N];
        std::memset(freq, 0, sizeof(freq));


        int n = s.size();
        int ans = 0;
        for(int L = 0, R = 0; R < n; ++R) {
            char curr = s[R];
            freq[curr]++;
            while(L < R && freq[curr] == 2) {
                freq[s[L++]]--;
            }

            ans = max(ans, R-L+1);
        }
        return ans;
    }
};
