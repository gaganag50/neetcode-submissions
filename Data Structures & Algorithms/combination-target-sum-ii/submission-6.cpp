
class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void helper(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level.
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since the array is sorted, later values will also be too large.
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i + 1: each array element can be used only once.
            helper(candidates, i + 1, target - candidates[i]);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        ans.clear();
        curr.clear();

        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);

        return ans;
    }
};
