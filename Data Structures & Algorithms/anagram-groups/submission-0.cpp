class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> counter(n, vector<int>(26, 0));

        map<vector<int>, vector<int>> m;

        for(int i = 0; i < n; ++i) {
            for(char c:strs[i]) {
                counter[i][c - 'a']++;
            }
        }
        for(int i = 0; i < n; ++i) {
            m[counter[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto p:m) {
            vector<string> group;
            for(int i: p.second) {
                group.push_back(strs[i]);
            }
            ans.push_back(group);
        }
        return ans;
    }
};
