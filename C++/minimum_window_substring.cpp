class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if(source.empty() || source.length()<target.length()) {
            return "";
        }
        
        const int ASCII_MAX=256;
        vector<int> exp(ASCII_MAX, 0);
        vector<int> cur(ASCII_MAX, 0);
        
        int start=0;
        int minStart=0;
        int minLen=INT_MAX;
        int cnt=0;
        
        for(int i=0; i<target.length(); ++i) {
            ++exp[target[i]];
        }
        
        for(int i=0; i<source.length(); ++i) {
            if(exp[source[i]]>0) {
                ++cur[source[i]];
                if(cur[source[i]]<=exp[source[i]]) ++cnt;
            }
            
            if(cnt==target.length()) {
                while(exp[source[start]]==0||exp[source[start]]<cur[source[start]]) {
                    --cur[source[start]];
                    ++start;
                }
                
                if(minLen>i-start+1) {
                    minStart=start;
                    minLen=i-start+1;
                }
            }
        }
        
        if(minLen==INT_MAX) {
            return "";
        }
        
        return source.substr(minStart, minLen);
    }
};

