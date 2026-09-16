class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x: s) {
            if(!s.count(x-1)){
                int curr = 1;

                while(s.count(x + 1)) {
                    curr++;
                    x = x + 1;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
