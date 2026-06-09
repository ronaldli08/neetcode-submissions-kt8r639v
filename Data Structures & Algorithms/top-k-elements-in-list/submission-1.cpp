class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> counter(2001, 0);

        for(const auto& num:nums) {
            ++counter[num + 1000];
        }
        multimap<int, int, greater<int>> m;
        for(int i = 0; i <= 2000; ++i) {
            m.insert({counter[i], i - 1000});
        }
        vector<int> ans(k);
        for(int i = 0; i < k; ++i) {
            ans[i] = m.begin()->second;
            m.erase(m.begin());
        }
        return ans;
    }
};
