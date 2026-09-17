class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int& val = nums[i];
            int idx = val-1;
            if(idx == i){continue;}
            if(nums[idx] == val){return val;}
            swap(nums[idx], val);
            i--;
        }
        return -1;
    }
};
