class Solution {
    deque<int> val, pos;
public:
    void insert(int v, int i) {
        while(!val.empty() && val.back() < v){
            val.pop_back();
            pos.pop_back();
        }
        val.push_back(v);
        pos.push_back(i);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return {};
        
        int i;
        for(i = 0; i < k-1; ++i) {
            int v = nums[i];
            insert(v, i);
        }
        vector<int> ans;
        int j = 0;
        while(i < n) {
            insert(nums[i], i);
            ans.push_back(val.front());
            i++;
            j++;
            while(!pos.empty() && pos.front() < j) {
                pos.pop_front();
                val.pop_front();
            }
        }
        return ans;
    }
};
