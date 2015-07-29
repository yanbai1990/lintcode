class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.empty()) return 0;
        stack<int> stk;
        
        for(const string tok:tokens) {
            if(!is_operator(tok)) {
                stk.push(stoi(tok));
            } else {
                int y=stk.top();
                stk.pop();
                int x=stk.top();
                stk.pop();
                if(tok=="+") {
                    x+=y;
                } else if(tok=="-") {
                    x-=y;
                } else if(tok=="*") {
                    x*=y;
                } else if(tok=="/") {
                    x/=y;
                }
                stk.push(x);
            }
        }
        
        int result=stk.top();
        stk.pop();
        return result;
    }
    
    bool is_operator(const string &op) {
        return op.length()==1 && string("+-*/").find(op)!=string::npos;
    }
};
