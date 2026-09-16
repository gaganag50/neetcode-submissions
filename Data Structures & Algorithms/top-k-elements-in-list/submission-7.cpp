class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k)pq.pop();
        }
        
        vector<int> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
