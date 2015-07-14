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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return isBalancedHeight(root)>=0;
    }
    
    int isBalancedHeight(TreeNode *root) {
        if(!root) return 0;
        int left=isBalancedHeight(root->left);
        int right=isBalancedHeight(root->right);
        if(left<0 || right<0 || abs(left-right)>1) return -1;
        return 1+max(left, right);
    }
};
