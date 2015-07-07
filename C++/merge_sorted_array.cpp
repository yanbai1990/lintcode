class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int pos=m+n-1;
        while(m>0 && n>0) {
            if(A[m-1]>B[n-1]) {
                A[pos--]=A[m-1];
                --m;
            } else {
                A[pos--]=B[n-1];
                --n;
            }
        }
        while(n>0) {
            A[pos--]=B[n-1];
            --n;
        }
    }
};
