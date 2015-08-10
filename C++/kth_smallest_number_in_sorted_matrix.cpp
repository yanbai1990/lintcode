class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    struct Compare {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.first>p2.first;
        }
    };
    
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        const int m=matrix.size();
        const int n=matrix[0].size();
        int ans=0;
        
        if(m<=n) {
            ans=horizontal_search(matrix, k);
        } else {
            ans=vertical_search(matrix, k);
        }
        
        return ans;
    }
    
    int horizontal_search(vector<vector<int> > &matrix, int k) {
        const int m=matrix.size();
        const int n=matrix[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int> >,  Compare> heap;
        
        for(int i=0; i<min(m,k); ++i) {
            heap.push(make_pair(matrix[i][0], i*n));
        }
        
        int kthSmallest=INT_MAX;
        while(!heap.empty() && k--) {
            kthSmallest=heap.top().first;
            int cur_row=(heap.top().second)/n;
            int cur_col=(heap.top().second)%n;
            heap.pop();
            if(cur_col+1<n) {
                heap.push(make_pair(matrix[cur_row][cur_col+1], cur_row*n+cur_col+1));
            }
        }
        
        return kthSmallest;
    }
    
    int vertical_search(vector<vector<int> > &matrix, int k) {
        const int m=matrix.size();
        const int n=matrix[0].size();
        priority_queue<pair<int, int>, vector<pair<int,int> >, Compare> heap;
        
        for(int i=0; i<min(n,k); ++i) {
            heap.push(make_pair(matrix[0][i], i));
        }
        
        int kthSmallest=INT_MAX;
        while(!heap.empty() && k--) {
            kthSmallest=heap.top().first;
            int cur_row=(heap.top().second)/n;
            int cur_col=(heap.top().second)%n;
            heap.pop();
            if(cur_row+1<m) {
                heap.push(make_pair(matrix[cur_row+1][cur_col], (cur_row+1)*n+cur_col));
            }
        }
        return kthSmallest;
    }
};
