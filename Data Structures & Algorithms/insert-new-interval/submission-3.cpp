class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // new interval can overlap with nothing and fit fine
        // new interval can overlap with the start of the next interval
        // new interval can overlap with the end of the previous interval
        // both of the above two

        if(intervals.empty()) return {newInterval};

        vector<vector<int>> output;

        int i;

        for(i = 0; i < intervals.size(); ++i) {
            if(intervals[i][1] >= newInterval[0]) break;
            else output.push_back(intervals[i]);
        }

        

        if(i >= intervals.size() || intervals[i][0] > newInterval[1]) {
            output.push_back(newInterval);
        }
        else {
            int start = min(intervals[i][0], newInterval[0]);
            int end = max(intervals[i][1], newInterval[1]);
            ++i;
            while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                end = max(intervals[i][1], newInterval[1]);
                i++;
            }
            output.push_back({start, end});
        }
        for(i = i; i < intervals.size(); ++i) {
            output.push_back(intervals[i]);
        }
        return output;
    }
};
