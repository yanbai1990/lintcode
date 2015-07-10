/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int length=getLength(head);
        return sortedListToBST(head, length);
    }
    
    TreeNode *sortedListToBST(ListNode *head, int length) {
        if(length==0) return NULL;
        if(length==1) return new TreeNode(head->val);
        ListNode *root_src=getNth(head, length/2+1);
        TreeNode *root=new TreeNode(root_src->val);
        root->left=sortedListToBST(head, length/2);
        root->right=sortedListToBST(getNth(head, length/2+2), (length-1)/2);
        return root;
    }
    
    int getLength(ListNode *head) {
        int len=0;
        while(head) {
            ++len;
            head=head->next;
        }
        return len;
    }
    
    ListNode *getNth(ListNode *head, int pos) {
        while(--pos) {
            head=head->next;
        }
        return head;
    }
};



