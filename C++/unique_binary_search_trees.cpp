class Solution1 {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        int count[n+1];
        count[0]=1;
        for(int i=1; i<=n; ++i) {
            int part_count=0;
            for(int j=0; j<i; ++j) {
                part_count+=count[j]*count[i-1-j];
            }
            count[i]=part_count;
        }
        return count[n];
    }
};

class Solution2 {
public:
    /**
     * catalan number
     *
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if(n==0 || n==1) return 1;
        return combination(2*n, n) - combination(2*n, n-1);
    }
    
    int combination(int n, int k) {
        long long count=1;
        for(int i=1; i<=k; ++i, --n) {
            count=count*n/i;
        }
        return count;
    }
};

