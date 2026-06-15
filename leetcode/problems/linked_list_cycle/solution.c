/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if( head ){
        struct ListNode *l1 = head;
        struct ListNode *l2 = head->next;
        while( l2 )
        {
            if( !l2->next )
                break;
            
            if( l1 == l2 )
                return true;
            
            l2 = l2->next->next;
            l1 = l1->next;
        }
    }
    return false;
}