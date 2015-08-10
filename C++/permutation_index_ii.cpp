class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        long long index=1;
        unordered_map<int, int> numCount;
        ++numCount[A.back()];
        
        for(int i=A.size()-2; i>=0; --i) {
            unordered_map<int, int> successorCount;
            ++numCount[A[i]];
            
            for(int j=i+1; j<A.size(); ++j) {
                if(A[i]>A[j]) {
                    ++successorCount[A[j]];
                }
            }
            
            for(const auto successor:successorCount) {
                --numCount[successor.first];
                index+=combination(numCount);
                ++numCount[successor.first];
            }
        }
        return index;
    }
    
    long long combination(const unordered_map<int, int>& numCount) {
        int n = 0;
        for (const auto& nc : numCount) {
            n += nc.second;
        }
        
        long long count = 1;
        for (const auto& nc : numCount) {
            // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
            for (int i = 1; i <= nc.second; ++i, --n) {
                count = count * n / i;
            }
        }
        
        return count;
    }
    
};
