/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head || head->next==NULL || k==0) return head;
        auto head2=head;
        int len=1;
        while(head2->next) {
            head2=head2->next;
            ++len;
        }
        head2->next=head;
        int l=len-k%len;
        while(l>0) {
            head2=head2->next;
            --l;
        }
        head=head2->next;
        head2->next=NULL;
        return head;
    }
};
