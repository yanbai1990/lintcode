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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        auto p=head, q=p->next;
        for(; q!=NULL; ) {
            if(q->val==p->val) {
                q=q->next;
            } else {
                p->next=q;
                p=q;
                q=p->next;
            }
        }
        if(p->next!=q) {
            p->next=q;
        }
        return head;
    }
};
