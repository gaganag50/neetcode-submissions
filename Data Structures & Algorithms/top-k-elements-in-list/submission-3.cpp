class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int a: nums){
            freq[a]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto it: freq){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = n; i > 0; --i) {
            if(!bucket[i].empty()) {
                for(int a: bucket[i]){
                    ans.push_back(a);
                    if(ans.size() == k)return ans;
                }
            }
        }
        return ans;
    }
};
