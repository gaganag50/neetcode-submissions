class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countOfZero = count(nums.begin(), nums.end(), 0);
        if (countOfZero > 1) {
            fill(nums.begin(), nums.end(), 0);
        } else if(countOfZero == 1) {
            int product = 1;
            for(int i: nums){
                if(i!=0)product *= i;

            }
            for(int& i: nums){
                if(i==0)
                    i = product;
                else i = 0;
            }

        } else {
            int product = 1;
            for(int i: nums)product *= i;
            for(int& i: nums){
                i = product/i;
            }
        }
        return nums;
    }
};
