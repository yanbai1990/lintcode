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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node=stk.top();
            stk.pop();
            res.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return res;
        
    }
};

class Solution2 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    
    void traversal(TreeNode *root, vector<int> &res) {
        if(!root) return;
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
};

class Solution3 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        return dividedAndConquer(root);
    }
    
    vector<int> dividedAndConquer(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        res.push_back(root->val);
        vector<int> root_left=dividedAndConquer(root->left);
        vector<int> root_right=dividedAndConquer(root->right);
        for(const auto i:root_left) {
            res.push_back(i);
        }
        for(const auto i:root_right) {
            res.push_back(i);
        }
        return res;
    }
};

