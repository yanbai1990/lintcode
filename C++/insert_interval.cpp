/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        size_t i=0;
        vector<Interval> result;
        while(i<intervals.size() && newInterval.start>intervals[i].end) {
            result.push_back(intervals[i++]);
        }
        
        while(i<intervals.size() && newInterval.end>=intervals[i].start) {
            newInterval.start=min(newInterval.start, intervals[i].start);
            newInterval.end=max(newInterval.end, intervals[i].end);
            ++i;
        }
        result.push_back(newInterval);
        
        result.insert(result.end(), intervals.begin()+i, intervals.end());
        
        return result;
    }
};
