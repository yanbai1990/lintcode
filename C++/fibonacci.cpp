class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n==1) return 0;
        if(n==2) return 1;
        int a=0;
        int b=1;
        int result;
        for(int i=3; i<=n; ++i) {
            result=a+b;
            a=b;
            b=result;
        }
        return result;
    }
};

