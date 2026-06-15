/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    
    struct ListNode *fast = head, *slow = head;
    struct ListNode *reverse = NULL, *current = NULL;
    int len = 1;
    
    
    // Find Middle and length as well   
    while( fast && fast->next && fast->next->next ){
        fast = fast->next->next;
        slow = slow->next;
        len += 2;
    }
    while( fast && (fast = fast->next) )
        len ++;
    
    // Detach the List into two pieces
    if( len%2 == 0 )
    {
        current = slow;
        slow = slow->next;
        current->next = NULL;
    }
    
    // Reverse 2nd List
    while( slow ) {
        current = slow;
        slow  = slow->next;
        current->next = reverse;
        reverse = current;
    }
    
    
    //Compare
    for(  ;head && reverse; head = head->next, reverse = reverse->next )
        if( head->val != reverse->val)
            return false;
    
    return true;
}