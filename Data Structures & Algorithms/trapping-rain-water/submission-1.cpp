class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> t(n);
        int T = a.back();
        for(int i = n - 2; i >= 0; --i) {
            t[i] = T;
            T = max(T, a[i]);
        }
        T = a.front();
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int currWater = max(0,min(t[i],T)- a[i]);
            T = max(T, a[i]);
            ans += currWater;
        }
        return ans;
    }
};
