class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int start=0;
        int maxLen=0;
        unordered_map<char, int> map;
        
        for(int i=0; i<s.length(); ) {
            if(map.find(s[i])==map.end()) {
                ++map[s[i]];
                maxLen=max(maxLen, i-start+1);
                ++i;
            } else {
                while(map.find(s[i])!=map.end()) {
                    --map[s[start]];
                    if(map[s[start]]==0) {
                        map.erase(s[start]);
                    }
                    ++start;
                }
            }
        }
        
        
        return maxLen;
    }
};
