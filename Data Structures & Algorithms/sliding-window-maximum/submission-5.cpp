class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d;
        vector<int> ans;

        for(int i = 0; i < n; ++i) {
            if(i >= k){
                if(d.front() == i-k)d.pop_front();
            }
            int el = nums[i];
            while(!d.empty() && nums[d.back()] < el){
                d.pop_back();
            }
            
            d.push_back(i);

            if(i >= k-1)
                ans.push_back(nums[d.front()]);
        }
        
        
        


    
    return ans;
    }
};
