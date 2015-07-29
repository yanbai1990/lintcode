class Solution1 {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> result({0});
        for(int i=0; i<n; ++i) {
            for(int j=result.size()-1; j>=0; --j) {
                result.push_back(result[j] | 1<<i);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> result;
        for(int i=0; i<1<<n; ++i) {
            result.push_back(i^(i>>1));
        }
        return result;
    }
};
