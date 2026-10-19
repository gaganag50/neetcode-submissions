class Solution {
    using pi = pair<int,int>;
    vector<vector<int>> ans;
    void helper(vector<int>& curr, vector<pi> nums, int i, const int& n,int target) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(i == n)return;
        auto [val, freq] = nums[i];

        for(int t = 1; t <= freq && (val*t) <= target; ++t){
            curr.push_back(val);
            helper(curr, nums, i + 1, n, target - (val*t));
        }
        for(int t = 1; t <= freq && (val*t) <= target; ++t){
            curr.pop_back();
        }
        helper(curr, nums, i + 1, n, target );
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        ans.clear();
        vector<int> curr;
        map<int,int> mp;
        for(int i : a) mp[i]++;
        vector<pi> nums;
        for(auto it: mp)nums.emplace_back(it.first, it.second);
        int n = nums.size();

        helper(curr,nums,0,n,target);
        return ans;
    }
};
