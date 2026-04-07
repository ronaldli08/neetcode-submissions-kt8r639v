class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0, p2 = 0;
        int size = nums.size();
        while(p2 < nums.size()) {
            if(nums[p2] != val) {
                nums[p1] = nums[p2];
                ++p1;
            }
            ++p2;
        }
        return p1;
    }
};