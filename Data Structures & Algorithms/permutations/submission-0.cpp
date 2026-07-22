class Solution {
public:
    vector<vector<int>> output;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        map<int, int> count;
        for(int num:nums) count[num]++;
        dfs(count, 0, nums.size(), cur);
        return output;
    }
    void dfs(map<int, int>& count, int i, int n, vector<int>& cur) {
        if(i == n) {
            output.push_back(cur);
            return;
        }

        for(auto itr = count.begin(); itr != count.end(); itr++) {
            auto p = *itr;
            if(count[p.first] == 0) {
                continue;
            }
            cur.push_back(p.first);
            count[p.first]--;
            dfs(count, i+1, n, cur);
            count[p.first]++;
            cur.pop_back();
        }
    }
};
