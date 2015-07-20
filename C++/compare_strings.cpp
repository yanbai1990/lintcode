class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_map<char, int> h;
        for (const auto& c: A) {
            ++h[c];
        }
        
        for (const auto& c: B) {
            if (--h[c] < 0) {
                return false;
            }
        }
        
        return true;
    }
};