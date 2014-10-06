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
        //find first interval
        //find the first number that newInterval.begin is smaller than
        int begin_i = 0;
        int begin_v = 0;
        int end_i = 0;
        int end_v = 0;
        int overlapping = 1;
        for (; begin_i != intervals.size(); ++begin_i) {
            if (intervals[begin_i].start >= newInterval.start) {
                begin_v = newInterval.start;
                break;
            }
            if (intervals[begin_i].end >= newInterval.start) {
                begin_v = intervals[begin_i].start;
                break;
            }
        }

        //if not overlapping
        if (begin_i == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        //find second interval
        end_i = begin_i;
        for (; end_i != intervals.size(); ++end_i) {
            if (intervals[end_i].start > newInterval.end) {
                end_v = newInterval.end;
                end_i--;
                break;
            }
            if (intervals[end_i].end >= newInterval.end) {
                end_v = intervals[end_i].end;
                break;
            }
        }

        //if extend to end
        if (end_i == intervals.size()) {
            end_i--;
            end_v = newInterval.end;
        }
        //if not overlapping
        if (end_i < begin_i) {
            intervals.insert(intervals.begin()+begin_i, newInterval);
        } else {
            //del shared intervals from begin_i to end_i
            intervals.erase(intervals.begin()+begin_i,intervals.begin()+end_i+1);
            //insert new interval<begin_v, end_v> at begin_i
            Interval temp(begin_v, end_v);
            intervals.insert(intervals.begin()+begin_i, temp);
        }

        return intervals;
    }
};