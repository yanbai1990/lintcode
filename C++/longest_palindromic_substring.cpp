class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        const int n=s.size();
        int max_len=1;
        int start=0;
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);
        
        for(int i=0; i<n; ++i) {
            f[i][i]=true;
            for(int j=0; j<i; ++j) {
                f[j][i]=s[j]==s[i] && (i-j<2 || f[j+1][i-1]);
                if(f[j][i] && max_len<(i-j+1)) {
                    max_len=i-j+1;
                    start=j;
                }
            }
        }
        
        return s.substr(start, max_len);
        
    }
};
