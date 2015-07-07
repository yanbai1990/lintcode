class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        size_t i=0;
        while(i<A.size()) {
            if(A[i]>0 && A[i]<=A.size() && A[A[i]-1]!=A[i]) {
                swap(A[i], A[A[i]-1]);
            } else {
                ++i;
            }
        }
        
        size_t ans=0;
        for(size_t i=0; i<A.size(); ++i) {
            if(A[i]!=i+1) {
                return i+1;
            }
        }
        return A.size()+1;
    }
};