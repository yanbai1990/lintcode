class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return false;
        int start=0;
        int end=A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(A[mid]==target) {
                return true;
            } else if(A[mid]<A[end]) {
                if(A[mid]<target && target<=A[end]) {
                    start=mid;
                } else {
                    end=mid;
                }
            } else if(A[mid]>A[end]){
                if(A[start]<=target && target<A[mid] ) {
                    end=mid;
                } else {
                    start=mid;
                }
            } else {
                end=mid-1;
            }
        }
        if(A[start]==target) return true;
        if(A[end]==target) return true;
        return false;
        
    }
};
