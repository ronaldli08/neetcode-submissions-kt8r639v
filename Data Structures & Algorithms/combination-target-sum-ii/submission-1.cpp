class Solution {
public:

    vector<vector<int>> output;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> cur{};

        dfs(candidates, cur, 0, candidates.size(), target);
        return output;
    }
    void dfs(vector<int>& candidates, vector<int>& cur, int i, int n, int remaining) {
        if(remaining <= 0 || i >= n) {
            if(remaining == 0) output.push_back(cur);
            return;
        }

        cur.push_back(candidates[i]);
        int old = candidates[i];
        dfs(candidates, cur, i+1, n, remaining - old);
        cur.pop_back();
        while (i < n && old == candidates[i]) i++;
        dfs(candidates, cur, i, n, remaining);
    }
};
