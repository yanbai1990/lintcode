class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if(k<1 || k>9) return -1;
        
        int cnt=0;
        int factor=1;
        int left_part=0, cur=0, right_part=0;
        
        while(n/factor>0) {
            left_part=n-(n/factor)*factor;
            cur=(n/factor)%10;
            right_part=n/(factor*10);
            
            if(cur<k) {
                cnt+=right_part*factor;
            } else if(k==cur) {
                cnt+=right_part*factor+left_part+1;
            } else {
                cnt+=(right_part+1)*factor;
            }
            
            factor*=10;
        }
        
        return cnt;
    }
};
