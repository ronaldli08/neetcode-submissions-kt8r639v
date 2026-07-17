class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, 
                            vector<pair<int, int>>, 
                            greater<pair<int, int>>> pq;
        int i = 0;
        sort(intervals.begin(), intervals.end());
        vector<int> output = queries;
        map<int, vector<int>> m;
        for(int i = 0; i < queries.size(); i++) {
            m[queries[i]].push_back(i);
        }

        int size = intervals.size();

        for(auto query: m) {
            while(i < size && intervals[i][0] <= query.first) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                pq.push({size, intervals[i][1]});
                i++;
            }

            while(!pq.empty() && pq.top().second < query.first) {
                pq.pop();
            }
            int ans;
            if(!pq.empty()) ans = pq.top().first;
            else ans = -1;
            for(int i:query.second) {
                output[i] = ans;
            }
        }
        return output;
    }
};
