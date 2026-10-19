class Solution {

    void helper(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int i, int n, int target, int sum) {
        if(i == n)return;
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(nums[i] + sum <= target) {
            curr.push_back(nums[i]);
            helper(ans, curr, nums, i, n, target,sum + nums[i]);
            curr.pop_back();
        }
        helper(ans, curr, nums, i + 1, n,target,sum);
    }


public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        int sum = 0;
        helper(ans, curr, nums, 0, n, target, sum);
        return ans;
        
    }
};
