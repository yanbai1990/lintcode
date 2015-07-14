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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode *buildTree(vector<int>::iterator pre_b, vector<int>::iterator pre_e, vector<int>::iterator in_b, vector<int>::iterator in_e) {
        if(pre_b==pre_e || in_b==in_e) return NULL;
        
        TreeNode *root=new TreeNode(*pre_b);
        auto pos=find(in_b, in_e, *pre_b);
        auto size=distance(in_b, pos);
        
        root->left=buildTree(next(pre_b), next(pre_b, size+1), in_b, next(in_b, size+1));
        root->right=buildTree(next(pre_b, size+1), pre_e, next(in_b, size+1), in_e);
        
        return root;
    }
    
};
