class Solution1 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int> > f(m, vector<int>(n, 0));
        f[0][0]=1;
        for(size_t i=1; i<m; ++i) {
            f[i][0]=f[i-1][0];
        }
        for(size_t j=1; j<n; ++j) {
            f[0][j]=f[0][j-1];
        }
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
        
    }
};

class Solution2 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<int> f(n, 0);
        
        for(size_t i=0; i<n; ++i) {
            f[i]=1;
        }
        
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                f[j]+=f[j-1];
            }
        }
        return f[n-1];
        
    }
};



