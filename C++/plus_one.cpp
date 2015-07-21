class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int carry=1;
        for(int i=digits.size()-1; i>=0; --i) {
            int sum=digits[i]+carry;
            carry=sum/10;
            sum%=10;
            digits[i]=sum;
        }
        if(carry>0) digits.insert(digits.begin(), carry);
        return digits;
    }
};