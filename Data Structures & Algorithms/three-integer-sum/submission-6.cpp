class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        set<vector<int>> ans;
        for(int i = 0; i < n-2; ++i) {
            int t = -a[i];
            for(int j = i + 1, k = n - 1; j < k;){
                int A = a[j], B = a[k];
                if(A + B == t){
                    ans.insert({-t,A,B});
                    j++;
                    k--;
                } else if(A + B < t){
                    j++;
                } else{
                    k--;
                }
            }
        }
        return {ans.begin(), ans.end()};
    }
};
