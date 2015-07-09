class Solution1 {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int *bits=new int[32];
        for(int i=0; i<32; ++i) {
            bits[i]=0;
        }
        
        for(auto i:A) {
            for(int j=0; j<32; ++j) {
                bits[j]+=i>>j&1;
                bits[j]%=3;
            }
        }
        
        int ans=0;
        for(int i=0; i<32; i++) {
            ans+=bits[i]<<i;
        }
        return ans;
    }
};

class Solution2 {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        const int n=A.size();
        int *bits=new int[32];
        for(int i=0; i<32; i++) {
            bits[i]=0;
        }
        
        int res=0;
        for(int i=0; i<32; ++i) {
            for(int j=0; j<n; j++) {
                bits[i]+=A[j]>>i & 1;
                bits[i]%=3;
            }
            res+=bits[i]<<i;
        }
        return res;
    }
};
