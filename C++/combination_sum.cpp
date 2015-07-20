class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, path, 0);
        return res;
    }
    
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &path, int index) {
        if(target==0) {
            res.push_back(path);
            return;
        }
        for(int i=index; i<candidates.size(); ++i) {
            if(candidates[i]<=target) {
                path.push_back(candidates[i]);
                combinationSum(candidates, target-candidates[i], res, path, i);
                path.pop_back();
            } else
                return;
        }
    }
};