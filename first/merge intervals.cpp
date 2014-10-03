/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a,const Interval &b){
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) return intervals;
        int i = 0;
        int begin_i;
        int end_i;
        int end_v;
        int begin_v;
        sort(intervals.begin(), intervals.end(), cmp);
        while (i < intervals.size()-1) {
            if (intervals[i].end >= intervals[i+1].start) {
                begin_i = i;
                end_i = i+1;
                end_v = max(intervals[i].end, intervals[end_i].end);
                begin_v = intervals[begin_i].start;
                ++i;
                while (i < intervals.size()-1 && end_v >= intervals[i+1].start) {
                    end_i = i+1;
                    end_v = max(end_v, intervals[end_i].end);
                    ++i;
                }
                intervals.erase(intervals.begin()+begin_i, intervals.begin()+end_i+1);
                Interval temp(begin_v, end_v);
                intervals.insert(intervals.begin()+begin_i, temp);
                i = begin_i+1;
            } else {
                ++i;
            }
        }
        return intervals;
    }
};