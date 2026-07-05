class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int m = a.front();
        int ans = 0;

        for(int i = 1; i < n; ++i) {
            ans = max(ans, a[i]-m);
            m = min(m,a[i]);
        }
        return ans;
    }
};
