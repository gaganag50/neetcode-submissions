class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), 0);
        if(cnt > 1){
            for(int& i: nums)i = 0;
            return nums;
        }
        if(cnt == 1){
            int product = 1;
            int idx = 0, index = 0;
            for(int& i: nums) {
                if(i != 0) {
                    product *= i;
                } else {
                    index = idx;
                }
                i = 0;
                idx++;
            }
            nums[index] = product;
            return nums;
        }
        else{
            int n = nums.size();
            vector<int> ans(n);
            for(int i = 0, product = 1; i < n; ++i) {
                ans[i] = product;
                product *= nums[i];
            }
            for(int i = n-1, product = 1; i >= 0; --i) {
                ans[i] *= product;
                product *= nums[i];
            }
            return ans;
        }
    }
};
