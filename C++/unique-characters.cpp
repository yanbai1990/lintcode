class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        unordered_set<char> used;
        for(const auto letter:str) {
            if(!used.insert(letter).second)
                return false;
        }
        return true;
    }
};
