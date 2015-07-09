/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        ListNode dummy(-1);
        dummy.next=head;
        auto pre=&dummy, cur=pre->next;
        while(cur->next) {
            auto tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
        }
        return dummy.next;
    }
};

