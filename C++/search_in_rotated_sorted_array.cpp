class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return -1;
        int start=0;
        int end=A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(A[mid]==target) {
                return mid;
            } else if(A[mid]<A[end]) {
                if(A[mid]<target && target<=A[end]) {
                    start=mid;
                } else {
                    end=mid;
                }
            } else {
                if(A[start]<=target && target<A[mid] ) {
                    end=mid;
                } else {
                    start=mid;
                }
            }
        }
        if(A[start]==target) return start;
        if(A[end]==target) return end;
        return -1;
    }
};
