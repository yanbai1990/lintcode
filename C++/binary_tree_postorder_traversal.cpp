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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
    
    void postorderTraversal(TreeNode* root, vector<int> &result) {
        if(root==NULL) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
};

class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if(root==NULL) return result;
        vector<int> left=postorderTraversal(root->left);
        vector<int> right=postorderTraversal(root->right);
        if(left.size()>0)
            for(auto i:left)
                result.push_back(i);
        if(right.size()>0)
            for(auto i:right)
                result.push_back(i);
        result.push_back(root->val);
        return result;
    }
};

class Solution3 {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if(!root) return result;
        stack<TreeNode*> stk;
        TreeNode *cur=root, *prev=NULL;
        do {
            while(cur!=NULL) {
                stk.push(cur);
                cur=cur->left;
            }
            
            prev=NULL;
            while(!stk.empty()) {
                cur=stk.top();
                stk.pop();
                if(cur->right!=prev) {
                    stk.push(cur);
                    cur=cur->right;
                    break;
                } else {
                    result.push_back(cur->val);
                    prev=cur;
                }
            }
        } while(!stk.empty());
        
        return result;
    }
};