class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int global_sum=INT_MIN;
        int local_sum=0;
        pair<int, int> result;
        
        for(int i=0, j=0; j<A.size(); ++j) {
            local_sum+=A[j];
            if(local_sum>global_sum) {
                global_sum=local_sum;
                result.first=i;
                result.second=j;
            }
            
            if(local_sum<0) {
                i=j+1;
                local_sum=0;
            }
        }
        return {result.first, result.second};
    }
};
