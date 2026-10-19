class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int i, int n){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < n; ++j){
            swap(nums[i], nums[j]);
            helper(nums,i+1,n);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        helper(nums,0,n);
        return ans;
    }
};
