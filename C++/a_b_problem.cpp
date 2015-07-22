class Solution1 {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int result=0;
        int carry=0;
        for(int i=0; i<32; ++i) {
            int a_bit=(a>>i)&1;
            int b_bit=(b>>i)&1;
            result |= (a_bit^b_bit^carry) <<i;
            if((a_bit==1 && b_bit==1) || ((a_bit==1||b_bit==1) && carry==1))
                carry=1;
            else
                carry=0;
        }
        return result;
    }
};

class Solution2 {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while(b!=0) {
            int sum=a^b;
            int carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return a;
    }
};

class Solution3 {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        if(b==0) return a;
        aplusb(a^b, (a&b)<<1);
    }
};