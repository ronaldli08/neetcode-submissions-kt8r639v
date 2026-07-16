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
        return i1.end < i2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int prevEnd = 0;

        for(const Interval& i:intervals) {
            if(i.start < prevEnd) return false;
            prevEnd = i.end;
        }
        return true;
    }
};
