class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counter(3, 0);
        for(int num:nums) {
            ++counter[num];
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(i < counter[0]) nums[i] = 0;
            else if(i < counter[0] + counter[1]) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};