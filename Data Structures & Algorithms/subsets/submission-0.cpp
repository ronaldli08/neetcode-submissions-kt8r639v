class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        recurse(nums, 0, subset, ans);
        return ans;
    }
    void recurse(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& ans) {
        if(i >= nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        recurse(nums, i+1, subset, ans);
        subset.pop_back();
        recurse(nums, i+1, subset, ans);
    }
};
