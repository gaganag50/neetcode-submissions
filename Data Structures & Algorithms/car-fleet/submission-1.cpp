class Solution {
public:
    int carFleet(int target, vector<int>& positions, vector<int>& speed) {
        using pi = pair<int,int>;
        vector<pi> v;
        int n = positions.size();
        for(int i = 0; i < n; ++i) {
            int position = positions[i];
            int sp = speed[i];
            v.emplace_back(position, sp);
        }
        sort(v.begin(), v.end());
        stack<long double> stk;
        for(int i = n - 1; i >= 0; --i) {
            long double time_taken = (target - v[i].first) / (long double)v[i].second;

            if(stk.empty() || time_taken > stk.top())
                stk.push(time_taken);
        }
        cout << endl;
        return stk.size();
    }
};
