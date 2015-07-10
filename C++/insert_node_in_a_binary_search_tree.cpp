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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if(root == NULL) return node;
        if(root->val == node->val) return root;
        if(root->val > node->val) {
            root->left = insertNode(root->left, node);
        }
        if(root->val < node->val) {
            root->right = insertNode(root->right, node);
        }
        
        return root;
    }
};

class Solution2 {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(!root) return node;
        auto ptr=root;
        auto ptr2=ptr;
        while(ptr) {
            ptr2=ptr;
            if(ptr->val<node->val) {
                ptr=ptr->right;
            } else if(ptr->val>node->val) {
                ptr=ptr->left;
            }
        }
        if(node->val<ptr2->val) {
            ptr2->left=node;
        } else {
            ptr2->right=node;
        }
        return root;
    }
};