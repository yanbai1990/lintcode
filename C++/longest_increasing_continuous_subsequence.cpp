class Solution1 {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int length=0;
        if(A.empty()) return length;
        
        length=lics(A);
        reverse(A.begin(), A.end());
        length=max(length, lics(A));
        
        return length;
    }
    
    int lics(vector<int> &A) {
        int length=0;
        int i=0, j=i+1;
        
        for( ; i<j&&i<A.size()-1&&j<A.size(); ) {
            if(A[j]>A[j-1]) {
                ++j;
            } else {
                length=max(length, j-i);
                i=j;
                j=i+1;
            }
        }
        
        length=max(length, j-i);
        
        return length;
    }
};

class Solution2 {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int lics_size=0, ics_cur_size=0; //increasing
        int ldcs_size=0, dcs_cur_size=0; //decreasing
        
        for(int i=0; i<A.size(); ++i) {
            if(i==0 || A[i]==A[i-1]) {
                lics_size=max(lics_size, ++ics_cur_size);
                ldcs_size=max(ldcs_size, ++dcs_cur_size);
            } else if(A[i]>A[i-1]) {
                lics_size=max(lics_size, ++ics_cur_size);
                dcs_cur_size=1;
            } else if(A[i]<A[i-1]) {
                ldcs_size=max(ldcs_size, ++dcs_cur_size);
                ics_cur_size=1;
            }
        }
        
        return max(lics_size, ldcs_size);
    }
};
