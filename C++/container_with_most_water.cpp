class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        //area is decided by the shorter integer
        if(heights.empty()) return 0;
        
        int left=0, right=heights.size()-1;
        int max_area=INT_MIN;
        
        while(left<right) {
            int area=min(heights[left], heights[right])*(right-left);
            max_area=max(max_area, area);
            if(heights[left]<=heights[right]) ++left;
            else --right;
        }
        
        return max_area;
    }
};
