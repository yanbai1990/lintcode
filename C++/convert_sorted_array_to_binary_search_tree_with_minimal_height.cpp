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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return sortedArrayToBST(A, 0, A.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &A, int start, int end) {
        if(start>end) return NULL;
        
        if(start==end) {
            TreeNode* leaf=new TreeNode(A[start]);
            return leaf;
        }
        
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(A[mid]);
        root->left=sortedArrayToBST(A, start, mid-1);
        root->right=sortedArrayToBST(A, mid+1, end);
        
        return root;
    }
};