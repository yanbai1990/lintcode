/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution1 {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    typedef enum {START, END} T;
    
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<T, int> > cnt;
        int curCnt=0, maxCnt=0;
        
        for(const auto interval:airplanes) {
            cnt.push_back(make_pair(START, interval.start));
            cnt.push_back(make_pair(END, interval.end));
        }
        
        sort(begin(cnt), end(cnt), [&](const pair<T, int> &p1, const pair<T, int> &p2){
            return p1.second!=p2.second?p1.second<p2.second:p1.first>p2.first;
        });
        
        for(const auto pair:cnt) {
            if(pair.first==START) {
                ++curCnt;
            } else {
                --curCnt;
            }
            maxCnt=max(maxCnt, curCnt);
        }
        
        return maxCnt;
    }
};

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution2 {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        multiset<int> cnt;
        int maxCnt=0;
        
        sort(begin(airplanes), end(airplanes), [&](const Interval &interval1, const Interval &interval2){
            return interval1.start!=interval2.start ? interval1.start<interval2.start : interval1.end<interval2.end;
        });
        
        for(const auto interval:airplanes) {
            cnt.insert(interval.end);
            while(*cnt.begin()<=interval.start) {
                cnt.erase(cnt.begin());
            }
            if(maxCnt<cnt.size()) {
                maxCnt=cnt.size();
            }
        }
        
        return maxCnt;
    }
};

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution3 {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        priority_queue<int, vector<int>, greater<int> > min_heap;
        int maxCnt=0;
        
        sort(begin(airplanes), end(airplanes), [&](const Interval &interval1, const Interval &interval2){
            return interval1.start!=interval2.start ? interval1.start<interval2.start : interval1.end<interval2.end;
        });
        
        for(const auto interval:airplanes) {
            min_heap.push(interval.end);
            while(min_heap.top()<=interval.start) {
                min_heap.pop();
            }
            if(maxCnt<min_heap.size()) {
                maxCnt=min_heap.size();
            }
        }
        
        return maxCnt;
    }
};


