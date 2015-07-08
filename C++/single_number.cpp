class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int ans=0;
        for(const auto i:A) {
            ans^=i;
        }
        return ans;
    }
};