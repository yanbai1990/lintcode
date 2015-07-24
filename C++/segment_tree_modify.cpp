/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if(!root) return;
        if(root->start==index && root->end==index) {
            root->max=value;
            return;
        }
        
        int mid=(root->start+root->end)/2;
        
        if(index>=root->start && index<=mid) {
            modify(root->left, index, value);
        } else if(index>=mid+1 && index<=root->end) {
            modify(root->right, index, value);
        }
        
        int left_max = root->left != nullptr? root->left->max : INT_MIN;
        int right_max = root->right != nullptr? root->right->max : INT_MIN;
        root->max=max(left_max, right_max);
    }
};
