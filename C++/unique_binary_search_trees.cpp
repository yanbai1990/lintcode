class Solution1 {
public:
    /**
     * catalan number
     *
     * @paramn n: An integer
     * @return: An integer
     */
    unordered_map<int, int> map;
    int numTrees(int n) {
        // write your code here
        if(n==0 || n==1) return 1;
        int sum=0;
        for(int m=1; m<=n; ++m) {
            int leftVal = 1;
            int rightVal = 1;
            if(map.find(m-1) != map.end())
                leftVal= map[m-1];
            else
            {
                leftVal = numTrees(m-1);
                map[m-1] = leftVal;
            }
            if(map.find(n-m) != map.end())
                rightVal = map[n-m];
            else
            {
                rightVal = numTrees(n-m);
                map[n-m] = rightVal;
            }
            
            sum+=leftVal*rightVal;
        }
        return sum;
    }
};

class Solution2 {
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

class Solution3 {
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

