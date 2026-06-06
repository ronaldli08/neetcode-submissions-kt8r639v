class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sum(0, nums, ans, comb, target);
        return ans;
    }
    void sum(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& comb, int target) {
        if(target == 0) {
            ans.push_back(comb);
            return;
        }
        else if(target < 0 || i >= nums.size()) return;
        comb.push_back(nums[i]);
        sum(i, nums, ans, comb, target - nums[i]);
        comb.pop_back();
        sum(i+1, nums, ans, comb, target);
    }
};
