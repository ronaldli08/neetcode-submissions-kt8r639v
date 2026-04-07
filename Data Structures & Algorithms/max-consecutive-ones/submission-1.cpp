class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int size = nums.size();
        int counter = 0;
        for(int n = 0; n < size; ++n) {
            if(nums[n]) {
                ++counter;
            }
            else {
                m = max(m, counter);
                counter = 0;
            }
        }
        return max(m, counter);
    }
};