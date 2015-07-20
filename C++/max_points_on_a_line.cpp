/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

#include <cfloat>
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int max_points=0;
        
        for(int i=0; i<points.size(); ++i) {
            unordered_map<double, int> slope_count;
            int same_point_num=1;
            
            for(int j=i+1; j<points.size(); ++j) {
                if(points[i].x==points[j].x && points[i].y==points[j].y)
                    ++same_point_num;
                else {
                    double slope=DBL_MAX;
                    if(points[i].x!=points[j].x)
                        slope=(points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                    ++slope_count[slope];
                }
                
            }
            
            int cur_max_points=same_point_num;
            for(const auto pair:slope_count) {
                cur_max_points=max(cur_max_points, pair.second+same_point_num);
            }
            max_points=max(max_points, cur_max_points);
        }
        return max_points;
    }
};
