class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n + 1);

        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for(int i = n; i > 0; --i) {
            if(!freq[i].empty()) {
                for(int element: freq[i]) {
                    ans.push_back(element);
                    if(ans.size() == k)return ans;
                }
            }
            

        }
        return ans;
    }
};
