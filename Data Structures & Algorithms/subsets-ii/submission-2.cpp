class Solution {
    using pi = pair<int,int>;
    vector<vector<int>> ans;
    vector<int> curr;
    void helper(vector<pi>& a, int i, int n){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        auto [val,freq] = a[i];
        for(int t = 1; t <= freq; ++t){
            curr.push_back(val);
            helper(a,i+1,n);
        }
        for(int t = 1; t <= freq; ++t)curr.pop_back();
        helper(a,i+1,n);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> mp;
        for(int i: nums)mp[i]++;
        vector<pi> a;
        for(auto it: mp)a.emplace_back(it.first, it.second);
        int n = a.size();
        helper(a,0,n);
        return ans;
    }
};
