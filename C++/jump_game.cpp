class Solution1 {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int reach=A[0];
        for(int i=0; i<A.size(); ++i) {
            if(reach<A[i]) {
                reach=A[i];
            }
            --reach;
            if(reach<=0) return false;
        }
        return reach>=0;
    }
};

class Solution2 {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int reach=0;
        for(int i=0; i<A.size(); ++i) {
            if(reach<i) {
                return false;
            }
            
            reach=max(reach, i+A[i]);
        }
        return reach>=A.size();
    }
};



