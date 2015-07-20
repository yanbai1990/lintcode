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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(!node || !node->next) return;
        auto node_to_delete=node->next;
        node->val=node_to_delete->val;
        node->next=node->next->next;
        delete node_to_delete;
    }
};
