class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int ans = 0;
        stack<int> stk;
        int i;
        for(i = 0; i < n; ++i) {
            int ht = heights[i];
            while(!stk.empty() && ht < heights[stk.top()]) {
                int l = stk.top(); stk.pop();
                int ht = heights[l];
                int dist = i - 1 - (stk.empty() ? -1 : stk.top());
                int currArea = ht * dist;
                ans = max(ans, currArea);

            }
            stk.push(i);
        }
        while(!stk.empty()) {
            int l = stk.top(); stk.pop();
            int ht = heights[l];
            int dist = i - 1 - (stk.empty() ? -1 : stk.top());
            int currArea = ht * dist;
            ans = max(ans, currArea);

        }

        
        return ans;
    }
};
