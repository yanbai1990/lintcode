class Solution1 {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int reach=A[0];
        int jump=0;
        for(int i=1; i<A.size(); ++i) {
            if(reach>=A.size()-1) return jump+1;
            if(reach<i+A[i]) {
                reach=i+A[i];
                ++jump;
            }
        }
        return jump;
    }
};

class Solution2 {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int start=0, end=0;
        int jump=0, reach=0;
        while(end<A.size()) {
            ++jump;
            for(int i=start; i<=end; ++i) {
                if(reach<A[i]+i) {
                    reach=A[i]+i;
                }
            }
            start=end+1;
            end=reach;
        }
        return jump;
    }
};

