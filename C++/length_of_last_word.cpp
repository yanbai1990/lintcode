class Solution1 {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int n=s.size();
        int left, right=n-1;
        
        if(n==0) return 0;
        while(s[right]==' ') --right;
        
        left=right;
        while(left>=0) {
            if(isalpha(s[left])) {
                --left;
                continue;
            } else if(s[left]==' ') {
                break;
            }
        }
        
        return left+1==right?1:right-left;
    }
};

class Solution2 {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int counter = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if (counter > 0) {
                    break;
                }
            } else {
                ++counter;
            }
        }
        return counter;
    }
};