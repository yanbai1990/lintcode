class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        vector<int> path;
        
        if(n<k) return res;
        
        combine(res, path, n, k, 1);
        return res;
    }
    
    void combine(vector<vector<int> > &res, vector<int> &path, int n, int k, int start) {
        if(path.size()==k) {
            res.push_back(path);
            return;
        }
        for(int i=start; i<=n&&(k-path.size()<=n-i+1); ++i) {
            path.push_back(i);
            combine(res, path, n, k, i+1);
            path.pop_back();
        }
    }
};
