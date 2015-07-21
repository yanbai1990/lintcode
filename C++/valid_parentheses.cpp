class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        string left="([{";
        string right=")]}";
        stack<char> stk;
        
        for(const char symbol:s) {
            if(left.find(symbol)!=string::npos) {
                stk.push(symbol);
            } else {
                if(stk.empty() || stk.top()!=left[right.find(symbol)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
