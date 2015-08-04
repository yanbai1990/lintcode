class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        int start=0;
        int maxLength=0;
        unordered_map<char, int> map;
        
        for(int i=0; i<s.size(); ++i) {
            ++map[s[i]];
            if(map.size()<=k) {
                maxLength=max(maxLength, i-start+1);
            } else {
                while(map.size()>k) {
                    --map[s[start]];
                    if(map[s[start]]==0) {
                        map.erase(s[start]);
                    }
                    ++start;
                }
            }
        }
        
        return maxLength;
    }
};
