/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   struct ListNode *l1 = headA, *l2 = headB;
    while( l1 != l2 ) {
        l1 = (l1) ? l1->next : headB;
        l2 = (l2) ? l2->next : headA;
    }
    
    return l2;
}