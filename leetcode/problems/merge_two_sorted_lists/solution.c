/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    // Get rid of these unnecessary handlers before corelogic
    if( l1 == NULL && l2 == NULL )
        return NULL;
    if( l1 == NULL )
        return l2;
    if (l2 == NULL )
        return l1;
    
    // 1->2->4
    // 3->4
    //
    // lh
    // 1->
    // lt
    
    struct ListNode *lh = NULL, *lt = NULL;
    
    while( l1 && l2 ) {
        if( lh ) { // There is a head Obvious there has to be a tail 
            
            if ( l1->val < l2->val ) {
                lt->next = l1;    // Tail NExt to correct Node,the lesser one
                l1 = l1->next;
            } else {
                lt->next = l2;    // Tail NExt to correct Node,the lesser one
                l2 = l2->next;
            }
            lt = lt->next;
        } else {
            // New List Head is still NULL
            
            if ( l1->val < l2->val ) {
                lh = l1;    // L1 is the least Entry let Head point to that
                l1 = l1->next;  // Move L1 to next Entry
            } else {
                lh = l2;    // L2 is the least Entry let head point to that
                l2 = l2->next; // Move L2 to Next Entry
            }
            
            lt = lh; // Both Tail and Head are same now
        }
        
        lt->next = NULL; //Detach this from Original Lisst
    }
    
    if( l1 )
        lt->next = l1;
    
    if( l2 )
        lt->next = l2;
    
        
    return lh;
}