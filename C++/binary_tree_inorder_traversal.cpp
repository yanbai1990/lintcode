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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        traversal(root, result);
        return result;
    }
    
    void traversal(TreeNode *root, vector<int> &result) {
        if(!root) return;
        traversal(root->left, result);
        result.push_back(root->val);
        traversal(root->right, result);
    }
};

class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        return traversal(root);
    }
    
    vector<int> traversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        vector<int> left=traversal(root->left);
        vector<int> right=traversal(root->right);
        for(const auto i:left) result.push_back(i);
        result.push_back(root->val);
        for(const auto i:right) result.push_back(i);
        return result;
    }
};

class Solution3 {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if(!root) return result;
        stack<const TreeNode*> stk;
        const TreeNode* node=root;
        
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node=node->left;
            } else {
                node=stk.top();
                stk.pop();
                result.push_back(node->val);
                node=node->right;
            }
        }
        return result;
    }
};
