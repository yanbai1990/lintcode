class Solution1 {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int start=0;
        int end=A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(A[mid]>A[mid-1] && A[mid]>A[mid+1]) {
                return mid;
            } else if(A[mid]<A[mid-1]) {
                end=mid;
            }  else {
                start=mid;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    
    int findPeak(vector<int> A) {
        // write your code here
        return findPeak(A, 0, A.size()-1);
    }
    
    int findPeak(vector<int> A, int start, int end) {
        if(start+1>=end) {
            return -1;
        }
        int mid=start+(end-start)/2;
        if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
            return mid;
        int res1=findPeak(A, start, mid);
        int res2=findPeak(A, mid, end);
        if(res1>0) return res1;
        return res2;
    }
};