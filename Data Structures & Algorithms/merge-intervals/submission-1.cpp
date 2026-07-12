class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;

        output.push_back(intervals[0]);

        int lastMerged = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= output[lastMerged][1]) {
                if(intervals[i][1] > output[lastMerged][1])
                    output[lastMerged][1] = intervals[i][1];
            }
            else {
                ++lastMerged;
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};
