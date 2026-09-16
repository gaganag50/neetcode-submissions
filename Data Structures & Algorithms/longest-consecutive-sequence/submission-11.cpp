class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
      
        for(auto it = s.begin(); it != s.end();) {
            int val = *it;

            ++it;

            int cur = 1;
            while(it != s.end() && val + 1 == (*it)) {
                cur++;
                val = *it;
                ++it;
               
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
