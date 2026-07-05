class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int a: nums){
            freq[a]++;
        }
        using pi = pair<int,int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(auto it: freq){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }    
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};  
