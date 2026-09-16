class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            int temperature = temperatures[i];
            while(!stk.empty() && temperature >= temperatures[stk.top()]) {
                stk.pop();
            }
            ans[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};
