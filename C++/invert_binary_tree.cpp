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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(root==NULL) return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        auto tmp=root->left;
        root->left=root->right;
        root->right=tmp;
    }
};

class Solution2 {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(root==NULL) return;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* node=queue.front();
            queue.pop();
            
            swap(node->left, node->right);
            if(node->left!=NULL) queue.push(node->left);
            if(node->right!=NULL) queue.push(node->right);
        }
    }
};
