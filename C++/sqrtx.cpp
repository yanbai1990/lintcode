class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x==0) return 0;
        int start=1;
        int end=x/2;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(mid>x/mid) {
                end=mid;
            } else if(mid<x/mid) {
                start=mid;
            } else {
                return mid;
            }
        }
        if(start==x/start) return start;
        if(end==x/end) return end;
    }
};
