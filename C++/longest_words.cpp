class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        int longest_str_size=0;
        for(auto str:dictionary) {
            if(str.size()>longest_str_size) {
                longest_str_size=str.size();
                res.clear();
                res.push_back(str);
            } else if(res.empty() || str.size()==longest_str_size) {
                res.push_back(str);
            } else
                continue;
        }
        return res;
    }
};
