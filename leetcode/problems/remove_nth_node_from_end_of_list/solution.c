/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode *fast = head, *current = NULL; 
    int i = 0;
    //
    //  n = 5
    //  1->2->3->4->5->
    // 
    //  n = 1
    //  1->2
    //
    //
    for(  ; fast ; fast = fast->next , i ++ ) {
        if( i == n )
            current = head;
        else if( i > n )
            current = current->next;
    }
    
    // This is the first element, head
    printf("%u ",current);
    if( i == n && current == NULL){
        head = head->next;
        return head;
    }
        
    
    if( current && current->next )
        current->next = current->next->next;
    
    return head;
    
    
}