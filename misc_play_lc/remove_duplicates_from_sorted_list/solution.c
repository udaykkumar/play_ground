/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode *h = head;
    while(h && h->next) {
        if (h->val == h->next->val) 
            h->next = h->next->next;
        else
            h = h->next;
    }
    
    return head;
}