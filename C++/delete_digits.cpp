class Solution1 {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        if(A.size() <= k)
            return "";
        if(k == 0)
            return A;
        
        int holdNum = A.size() - k -1;
        string result = "";
        
        // ending point is exclusive
        getDeleteString(result, A.size()-k, 0, A.size()-holdNum, A);
        
        int start=0;
        while(result[start]=='0') {
            ++start;
        }
        return result.substr(start, result.length()-start+1);
    }
    
    void getDeleteString(string& result, int level, int start, int end, string& A)
    {
        if(start >= end || level ==0)
            return;
        char smallest = A[start];
        int newStart = start + 1;
        for(unsigned int i = start; i < end; ++i)
        {
            //if two to be the same, choose the first one, ex: 1785123, k = 4
            if(A[i] < smallest)
            {
                newStart = i+1;
                smallest = A[i];
            }
        }
        result += smallest;
        getDeleteString(result, level - 1, newStart, ++end, A);
    }
};

class Solution2 {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        const int n=A.size();
        if(n <= k)
            return "";
        if(k == 0)
            return A;
        
        string ans="";
        for(int i=0, j=k+1; j<=n;) {
            char c=*min_element(A.begin()+i, A.begin()+j);
            ans.push_back(c);
            i=A.find(c, i)+1;
            ++j;
        }
        
        int start=0;
        while(ans[start]=='0') {
            ++start;
        }
        
        return ans.substr(start, ans.length()-start+1);
    }
};

