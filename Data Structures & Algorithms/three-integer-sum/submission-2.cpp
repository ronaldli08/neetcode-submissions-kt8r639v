class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        set<vector<int>> output;
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i) {
            int num = nums[i];
            int p1 = i + 1;
            int p2 = n - 1;
            while(p1 < p2) {
                if(nums[p1] + nums[p2] + num == 0) {
                    output.insert({num, nums[p1], nums[p2]});
                    ++p1;
                }
                else if(nums[p1] + nums[p2] + num < 0) {
                    ++p1;
                }
                else {
                    --p2;
                }
            } 
        }
        return vector<vector<int>>(output.begin(), output.end());
    }
};
