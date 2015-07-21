class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        int sign=n>0?1:-1;
        int mod=0;
        int result=0;
        
        n=abs(n);
        while(n>0) {
            mod=n%10;
            n/=10;
            if(result>INT_MAX/10 || (result==INT_MAX/10&&mod==INT_MAX%10))
                return 0;
            else
                result=result*10+mod;
        }
        return result*sign;
    }
};
