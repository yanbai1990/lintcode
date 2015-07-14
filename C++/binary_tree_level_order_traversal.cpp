/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution1 {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        vector<int> level;
        queue<TreeNode*> cur_level;
        queue<TreeNode*> next_level;
        if(!root) return res;
        cur_level.push(root);
        while(!cur_level.empty()) {
            while(!cur_level.empty()) {
                auto node=cur_level.front();
                cur_level.pop();
                level.push_back(node->val);
                if(node->left) next_level.push(node->left);
                if(node->right) next_level.push(node->right);
            }
            res.push_back(level);
            swap(cur_level, next_level);
            level.clear();
        }
        return res;
    }
};

class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        levelOrder(root, 0, res);
        return res;
    }
    
    void levelOrder(TreeNode *root, size_t level, vector<vector<int> > &res) {
        if(!root) return;
        if(level>=res.size()) res.push_back({});
        res[level].push_back(root->val);
        levelOrder(root->left, level+1, res);
        levelOrder(root->right, level+1, res);
    }
};

