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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        build(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
    
    template<typename T>
    TreeNode *build(T in_begin, T in_end, T post_begin, T post_end) {
        if(in_begin==in_end || post_begin==post_end) return NULL;
        
        auto node=prev(post_end);
        TreeNode *root=new TreeNode(*node);
        auto in_end_left=find(in_begin, in_end, *node);
        auto size_left=distance(in_begin, in_end_left);
        auto new_post_begin=next(post_begin, size_left);
        
        root->left=build(in_begin, in_end_left, post_begin, new_post_begin);
        root->right=build(next(in_end_left), in_end, new_post_begin, prev(post_end));
        return root;
    }
};
