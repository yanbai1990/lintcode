class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.empty()) return 0;
        int start=1;
        int end=*max_element(L.cbegin(), L.cend());
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(pieceCount(L, mid)<k) {
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        
        return start-1;
    }
    
    int pieceCount(vector<int> L, int len) {
        int count=0;
        for(const auto i:L) {
            count+=i/len;
        }
        return count;
    }
};
