class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int left=0, right=s.size()-1;
        while(s[left]==' ') ++left;
        while(s[right]==' ') --right;
        while(left<right) {
            if(!isalnum(s[left])) ++left;
            else if(!isalnum(s[right])) --right;
            else if(tolower(s[left])!=tolower(s[right])) return false;
            else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
