/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        if (intervals.empty()) return result;
        Interval probe = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= probe.end) {
                probe.end = max(probe.end, intervals[i].end);
            } else {
                result.push_back(probe);
                probe = intervals[i];
            }
        }
        result.push_back(probe);
        return result;
    }
};
