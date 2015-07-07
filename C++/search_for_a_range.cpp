class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return {-1, -1}; //check empty case in search problem
        const int begin = lower_bound(A, target);
        const int end = upper_bound(A, target);
        
        return {begin, end};
    }
    
private:
    int lower_bound(vector<int> &A, int target) {
        int start = 0;
        int end = A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(target==A[mid]) end=mid;
            else if(target<A[mid]) end=mid;
            else if(target>A[mid]) start=mid;
        }
        if(target==A[start]) return start;
        else if(target==A[end]) return end;
        return -1;
    }
    
    int upper_bound(vector<int> &A, int target) {
        int start = 0;
        int end = A.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(target==A[mid]) start=mid;
            else if(target<A[mid]) end=mid;
            else if(target>A[mid]) start=mid;
        }
        if(target==A[end]) return end;  //care endside first
        if(target==A[start]) return start;
        return -1;
    }
};
