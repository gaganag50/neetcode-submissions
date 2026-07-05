class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int a = nums[i];
            int b = target - a;
            if(mp.count(b)) {
                return {mp[b], i};
            }
            if(!mp.count(a)) {
                mp[a] = i;
            }
        }
        return {};
    }
};
