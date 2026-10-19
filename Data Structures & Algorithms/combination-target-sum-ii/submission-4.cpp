class Solution {

    using pi = pair<int,int>;
    vector<vector<int>> ans;
    void helper(vector<int>& curr, vector<pi>& nums, int i, int n, int target, int sum) {
        if(sum == target){
            if(true) {
                // vis.insert(curr);
                ans.push_back(curr);
            }
            return;
        }
        if(i == n)return;
        int val = nums[i].first;
        
        if(val + sum <= target) {
            int freq = nums[i].second;
            for(int t = 1; t <= freq; ++t){
                for(int j = 0; j < t; ++j)
                    curr.push_back(val);
                helper( curr, nums, i+1, n, target,sum + (t*val));
                for(int j = 0; j < t; ++j)
                    curr.pop_back();
                
            }
            
            
        }
        helper( curr, nums, i + 1, n,target,sum);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        unordered_map<int,int> mp;
        for(int i: a)mp[i]++;
        vector<pi> nums;
        for(auto it: mp){
            nums.emplace_back(it.first, it.second);
        }
        /*
        9,2,2,4,6,1,5

        1 -> 1
        2 -> 2
        4 -> 1
        5 -> 1
        6 -> 1
        9 -> 1
        */



        vector<int> curr;
        int n = nums.size();
        int sum = 0;
        helper( curr, nums, 0, n, target, sum);
        return ans;
    }
};
