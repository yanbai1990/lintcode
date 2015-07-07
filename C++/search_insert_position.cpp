class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return 0;
        int start=0;
        int end=A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(A[mid]==target) {
                end=mid;
            } else if(A[mid]<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(A[start]>=target) return start;
        else if(A[end]>=target) return end;
        else return end+1;
    }
};
