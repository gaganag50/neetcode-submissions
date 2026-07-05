class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for(int i = 0, j = n - 1; i < j;) {
            int a = nums[i], b = nums[j];
            if(a + b == target) {
                if(a == b) {
                    ans = {mp[a][0],mp[a][1]};
                } else {
                    ans = {mp[a][0],mp[b][0]};
                }
                
                j--;
            } else if( a + b < target) {
                i++;
            } else {
                j--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
