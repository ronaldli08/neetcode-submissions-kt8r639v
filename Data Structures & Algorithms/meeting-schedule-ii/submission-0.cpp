/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int rooms = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < intervals.size(); i++) {
            if(!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
};
