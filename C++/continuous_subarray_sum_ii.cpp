class Solution1 {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        if(A.empty()) return {-1,-1};
        
        vector<int> circular(2,0), non_circular(2,0);
        
        if(maxSum(A, non_circular)>circularMaxSum(A, circular)) {
            return non_circular;
        } else {
            return circular;
        }
    }
    
    //kadane algorithm
    int maxSum(vector<int> &A, vector<int> &non_circular) {
        int global_sum=INT_MIN;
        int local_sum=0;
        for(int i=0, j=0; j<A.size(); ++j) {
            local_sum+=A[j];
            if(global_sum<local_sum) {
                global_sum=local_sum;
                non_circular[0]=i;
                non_circular[1]=j;
            }
            
            if(local_sum<0) {
                local_sum=0;
                i=j+1;
            }
        }
        return global_sum;
    }
    
    int circularMaxSum(vector<int> &A, vector<int> &circular) {
        int sum=0;
        for(int &i:A) {
            sum+=i;
            i*=-1;
        }
        int result=sum+maxSum(A, circular);
        circular[0]=circular[0]>0?circular[0]-1:A.size()-1;
        circular[1]=circular[1]<A.size()-1?circular[1]+1:0;
        swap(circular[0], circular[1]);
        if(result==0) return INT_MIN;
        return result;
    }
};

class Solution2 {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        if(A.empty()) return {-1,-1};
        
        vector<int> circular(2,0), non_circular(2,0);
        
        if(maxSum(A, non_circular)>circularMaxSum(A, circular)) {
            return non_circular;
        } else {
            return circular;
        }
    }
    
    //kadane algorithm
    int maxSum(vector<int> &A, vector<int> &non_circular) {
        int global_sum=INT_MIN;
        int local_sum=0;
        for(int i=0, j=0; j<A.size(); ++j) {
            local_sum+=A[j];
            if(global_sum<local_sum) {
                global_sum=local_sum;
                non_circular[0]=i;
                non_circular[1]=j;
            }
            
            if(local_sum<0) {
                local_sum=0;
                i=j+1;
            }
        }
        return global_sum;
    }
    
    int circularMaxSum(vector<int> &A, vector<int> &circular) {
        // Max subarray sum starts at index 0 and ends at or before index i.
        vector<int> max_sum_from_start(A.size());
        vector<int> max_j(A.size());
        int sum = A.front();
        max_sum_from_start[0] = sum;
        max_j[0] = 0;
        for (int j = 1; j < A.size(); ++j) {
            sum += A[j];
            if (sum > max_sum_from_start.back()) {
                max_sum_from_start[j] = sum;
                max_j[j] = j;
            } else {
                max_sum_from_start[j] = max_sum_from_start[j - 1];
                max_j[j] = max_j[j - 1];
            }
        }
        
        // Max subarray sum starts at index i + 1 and ends at the last element.
        vector<int> max_sum_to_end(A.size());
        vector<int> max_i(A.size());
        sum = 0;
        max_sum_to_end.back() = sum;
        max_i.back() = 0;
        for (int i = A.size() - 2; i >= 0; --i) {
            sum += A[i + 1];
            if (sum > max_sum_to_end[i + 1]) {
                max_sum_to_end[i] = sum;
                max_i[i] = i + 1;
            } else {
                max_sum_to_end[i] = max_sum_to_end[i + 1];
                max_i[i] = max_i[i + 1];
            }
        }
        
        // Calculates the max subarray which is circular.
        int result = INT_MIN;
        for (int i = 0; i < A.size(); ++i) {
            if (max_sum_from_start[i] + max_sum_to_end[i] > result) {
                result = max_sum_from_start[i] + max_sum_to_end[i];
                circular[0] = max_i[i], circular[1] = max_j[i];
            }
        }
        
        return result;
    }
};

