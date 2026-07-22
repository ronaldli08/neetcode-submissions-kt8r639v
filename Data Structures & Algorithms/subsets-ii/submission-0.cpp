class Solution {
public:

    set<vector<int>> output;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(nums, 0, nums.size(), cur);
        return vector<vector<int>>(output.begin(), output.end());
    }
    void backtrack(vector<int>& nums, int i, int n, vector<int>& cur) {
        if(i == n) {
            output.insert(cur);
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, i+1, n, cur);
        cur.pop_back();
        backtrack(nums, i+1, n, cur);
    }
};
