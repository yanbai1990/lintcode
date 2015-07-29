class Solution1 {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if(divisor==0) return dividend>=0?INT_MAX:INT_MIN;
        if(dividend==0) return 0;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        bool isNegative=(dividend>0)^(divisor>0);
        int result=0;
        
        long long a=llabs(dividend);
        long long b=llabs(divisor);
        
        while(a>=b) {
            int shift=0;
            while(a>=(b<<shift)) {
                ++shift;
            }
            a-=b<<(shift-1);
            result+=1<<(shift-1);
        }
        
        return isNegative?-result:result;
    }
};

class Solution2 {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if(divisor==0) return dividend>=0?INT_MAX:INT_MIN;
        if(dividend==0) return 0;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        bool isNegative=(dividend>0)^(divisor>0);
        
        double a=fabs(dividend);
        double b=fabs(divisor);
        
        long long result=exp(log(a)-log(b));
        
        if(isNegative) result=-result;
        
        if(result>INT_MAX) return INT_MAX;
        
        return result;
    }
};


