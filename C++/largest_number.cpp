
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        sort(num.begin(), num.end(), [](const int &a, const int &b) {
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        
        string ans="";
        
        for(const auto i:num) {
            ans+=to_string(i);
        }
        
        if(ans[0]=='0') {
            return "0";
        }
        
        return ans;
    }
};