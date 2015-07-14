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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(!root) return root;
        if(root->val>value) {
            root->left=removeNode(root->left, value);
        }else if(root->val<value) {
            root->right=removeNode(root->right, value);
        }else {
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            auto node=root;
            root=findMax(node->left);
            root->left=deleteMax(node->left);
            root->right=node->right;
        }
        return root;
    }
    
    TreeNode* findMax(TreeNode* node) {
        while(node && node->right) {
            node=node->right;
        }
        return node;
    }
    
    TreeNode* deleteMax(TreeNode* node) {
        if(!node->left && !node->right) return NULL;
        TreeNode *root=node, *parent=NULL;
        while(node && node->right) {
            parent=node;
            node=node->right;
        }
        if(parent) parent->right=node->left;
        return root;
    }
};


class Solution2 {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(!root) return root;
        if(value<root->val) {
            root->left=removeNode(root->left, value);
        } else if(value>root->val) {
            root->right=removeNode(root->right, value);
        } else {
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else {
                TreeNode *node=root;
                root=findMin(node->right);
                root->right=deleteMin(node->right);
                root->left=node->left;
            }
        }
        return root;
    }
    
    TreeNode *findMin(TreeNode *node) {
        while(node && node->left) {
            node=node->left;
        }
        return node;
    }
    
    TreeNode *deleteMin(TreeNode *node) {
        if(!node->left && !node->right) {
            return NULL;
        }
        TreeNode *root=node, *parent=NULL;
        while(node && node->left) {
            parent=node;
            node=node->left;
        }
        if(parent) parent->left=node->right;
        return root;
        
    }
};

