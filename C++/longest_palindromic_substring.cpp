class Solution1 {
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

//http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
class Solution2 {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string s) {
        // Write your code here
        string T=preprocess(s);
        int n=T.size();
        vector<int> P(n);
        int C=0, R=0;
        int centerIndex=0, maxLen=0;
        
        for(int i=1; i<n-1; ++i) {
            int i_mirror=2*C-i;
            
            P[i]=P[i_mirror]>(R-i) ? min(R-i, P[i_mirror]) : 0;
            
            while(T[i+1+P[i]]==T[i-1-P[i]]) {
                ++P[i];
            }
            
            if(i+P[i]>R) {
                C=i;
                R=i+P[i];
            }
        }
        
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        return s.substr((centerIndex-1-maxLen)/2, maxLen);
    }
    
    string preprocess(string s) {
        int n = s.length();
        if (n == 0) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
        
        ret += "#$";
        return ret;
    }
};

