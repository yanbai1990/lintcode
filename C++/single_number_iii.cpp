class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int x_xor_y=0;
        for(const auto i:A) {
            x_xor_y^=i;
        }
        
        int bit=x_xor_y&~(x_xor_y-1);
        int x=0;
        for(const auto i:A) {
            if(bit&i) {
                x^=i;
            }
        }
        return {x, x_xor_y^x};
    }
};
