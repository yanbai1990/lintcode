class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        const int n=A.size();
        int positiveNum=0;
        for(const int i:A) {
            positiveNum+=i>0?1:0;
        }
        
        int negativePos=0, positivePos=1;
        if(2*positiveNum>n) {
            positivePos=0;
            negativePos=1;
        }
        
        while(negativePos<n && positivePos<n) {
            while(negativePos<n && A[negativePos]<0) negativePos+=2;
            while(positivePos<n && A[positivePos]>0) positivePos+=2;
            if(negativePos<n &&positivePos<n) {
                swap(A[negativePos], A[positivePos]);
                negativePos+=2;
                positivePos+=2;
            }
        }
    }
};
