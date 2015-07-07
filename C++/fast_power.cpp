class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        return fastPower2(a, b, n);
    }
    
    int fastPower2(long long a, int b, int n) {
        if(n==0) return 1%b;
        if(n%2==1) return a*fastPower2((a*a)%b, b, n/2)%b;
        else return fastPower2((a*a)%b, b, n/2);
    }
};
