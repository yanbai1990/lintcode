class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > result;
        vector<int> path;
        sort(num.begin(), num.end());
        combination(num, target, result, path, 0);
        return result;
    }
    
    void combination(vector<int> &num, int target, vector<vector<int> > &result, vector<int> &path, int index) {
        if(target==0) {
            result.push_back(path);
            return;
        }
        
        for(int i=index; i<num.size() && num[i]<=target; ++i) {
            if(i==index || num[i]!=num[i-1]) {
                path.push_back(num[i]);
                combination(num, target-num[i], result, path, i+1);
                path.pop_back();
            }
        }
    }
};
