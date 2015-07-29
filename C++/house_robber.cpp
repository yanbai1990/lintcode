class Solution1 {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if(A.empty()) return 0;
        
        const int n=A.size();
        vector<long long> f(n, 0);
        f[0]=A[0];
        
        
        for(int i=1; i<n; ++i) {
            if(i<2) {
                f[i]=max(f[i-1], static_cast<long long>(A[i]));
            } else {
                f[i]=max(f[i-1], f[i-2]+A[i]);
            }
        }
        
        return f[n-1];
    }
};

class Solution2 {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if(A.empty()) return 0;
        
        const int n=A.size();
        long long before_cur_1pos=0;
        long long before_cur_2pos=0;
        
        
        for(int i=0; i<n; ++i) {
            long long cur=before_cur_2pos+A[i];
            before_cur_2pos=before_cur_1pos;
            before_cur_1pos=max(cur, before_cur_1pos);
        }
        
        return max(before_cur_1pos, before_cur_2pos);
    }
};

