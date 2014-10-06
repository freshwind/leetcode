/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i = 0;
        for (; i < intervals.size(); ++i) {
            if (newInterval.start < intervals[i].start) {
                break;
            }
            if (newInterval.start <= intervals[i].end) {
                newInterval.start = intervals[i].start;
                break;
            }
        }
        int j = i;
        for (; j < intervals.size(); ++j) {
            if (newInterval.end < intervals[j].start) {
                break;
            }
            if (newInterval.end <= intervals[j].end) {
                newInterval.end = intervals[j].end;
                ++j;
                break;
            }
        }
        if (j > i && !intervals.empty()) {
            intervals.erase(intervals.begin()+i, intervals.begin()+j);
        }
        intervals.insert(intervals.begin()+i, newInterval);
        return intervals;
    }
};
