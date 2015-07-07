class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int pos=A.size();
        for(int i=0; i<pos; ) {
            if(A[i]==elem) {
                swap(A[i], A[--pos]);
            } else {
                ++i;
            }
        }
        return pos;
    }
};
