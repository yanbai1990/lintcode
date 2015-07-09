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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode dummy(-1);
        dummy.next=head;
        auto p=&dummy, q=&dummy;
        while(n>0) {
            p=p->next;
            --n;
        }
        
        while(p->next!=NULL) {
            p=p->next;
            q=q->next;
        }
        
        ListNode* tmp=q->next;
        q->next=q->next->next;
        delete tmp;
        return dummy.next;
        
    }
};



