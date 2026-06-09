class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        for(const auto& p:count) {
            pq.push({p.second, p.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans(k);
        for(int i = 0; i < k;++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
