//http://www.geekviewpoint.com/java/numbers/permutation_index
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long index=1;
        int position=2;
        long long factor=1;
        
        for(int i=A.size()-2; i>=0; --i) {
            int successors=0;
            for(int j=i+1; j<A.size(); ++j) {
                if(A[j]<A[i]) {
                    ++successors;
                }
            }
            index+=factor*successors;
            factor*=position;
            ++position;
        }
        
        return index;
    }
};
