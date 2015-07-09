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
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode less_dummy(-1);
        ListNode more_dummy(-1);
        auto p=head, less=&less_dummy, more=&more_dummy;
        while(p) {
            if(p->val<x) {
                less->next=p;
                less=less->next;
            } else {
                more->next=p;
                more=more->next;
            }
            p=p->next;
        }
        less->next=more_dummy.next;
        more->next=NULL;
        return less_dummy.next;
    }
};



