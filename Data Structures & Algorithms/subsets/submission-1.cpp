class Solution {
    void helper(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int i, int n) {
        if(i == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(ans, curr, nums, i + 1, n);
        curr.pop_back();
        helper(ans, curr, nums, i + 1, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        helper(ans, curr, nums, 0, n);
        return ans;
    }
};
