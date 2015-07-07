class Solution1 {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        const int n=nums.size();
        vector<long long> ans(n, 0);
        for(int i=0; i<n; i++) {
            long long sum=1L;
            for(int j=0; j<n; j++) {
                if(i!=j) {
                    sum*=nums[j];
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};

class Solution2 {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        const int n=nums.size();
        vector<long long> ans(n, 0);
        vector<long long> left_ans(n, 0);
        vector<long long> right_ans(n, 0);
        
        left_ans[0]=1;
        for(int i=1; i<n; ++i) {
            left_ans[i]=left_ans[i-1]*nums[i-1];
        }
        
        right_ans[n-1]=1;
        for(int i=n-2; i>=0; --i) {
            right_ans[i]=right_ans[i+1]*nums[i+1];
        }
        
        for(int i=0; i<n; ++i) {
            ans[i]=left_ans[i]*right_ans[i];
        }
        
        return ans;
    }
};
