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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(intervals.size()==0) return {};
        
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start<b.start;
        });
        
        vector<Interval> result({intervals[0]});
        for(size_t i=1; i<intervals.size(); ++i) {
            Interval &prev=result.back();
            if(prev.end>=intervals[i].start) {
                prev.end=max(prev.end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
        
    }
};
