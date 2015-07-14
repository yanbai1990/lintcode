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
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    
    bool isValidBST(TreeNode *root) {
        // write your code here
        isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode *root, long lower, long upper) {
        if(!root) return true;
        return root->val>lower && root->val<upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
    
};
