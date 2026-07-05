class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int ans = 0, curr;
        for(int i = 0, j = n - 1; i < j;){
            int A = a[i], B = a[j];
            curr = 0;
            int dist = j-i;
            if(A < B){
                i++;
                curr = A * dist;
            } else {
                j--;
                curr = B * dist;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
