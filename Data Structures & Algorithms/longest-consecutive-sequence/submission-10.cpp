class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> st(nums.begin(), nums.end());

        auto it = st.begin();
        
        int ans = 1;
        while(it != st.end()) {
            int start = *it;
            int curr = 1;
            while(st.find(start + 1) != st.end()){
                it++;
                curr++;
                start++;
            }
            ans = max(ans, curr);
            it++;
        }
        return ans;
    }
};
