class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string result("1");
        for(int i=1; i<n; ++i) {
            result=move(getNext(result));
        }
        return result;
    }
    
    string getNext(string s) {
        stringstream ss;
        for(int i=0; i<s.size(); ++i) {
            int cnt=1;
            while(i<s.size()-1 && s[i]==s[i+1]) {
                ++cnt;
                ++i;
            }
            ss << cnt << s[i];
        }
        return ss.str();
    }
};
