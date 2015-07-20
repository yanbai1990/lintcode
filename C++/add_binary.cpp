class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string result;
        int result_len=max(a.size(), b.size());
        int carry=0;
        for(int i=0; i<result_len; ++i) {
            int a_i_bit=i>=a.size()?0:a[a.size()-1-i]-'0';
            int b_i_bit=i>=b.size()?0:b[b.size()-1-i]-'0';
            int sum=a_i_bit+b_i_bit+carry;
            carry=sum/2;
            sum%=2;
            result.push_back(sum+'0');
        }
        if(carry>0) result.push_back('1');
        reverse(begin(result), end(result));
        return result;
    }
};