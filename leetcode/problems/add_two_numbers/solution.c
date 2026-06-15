/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    
    struct ListNode *l3 = NULL, *l3Tail = NULL, *Current = NULL;
    int carry = 0;
   while( l1 || l2 )
    {
        int v1 = 0, v2 = 0, v3 = 0; 
        
            v1 = (l1) ? l1->val : 0;
            v2 = (l2) ? l2->val : 0;
            v3 = v1 + v2 + carry;
            carry = v3/10;
            v3   %= 10;
        
        struct ListNode *n = NULL;
        
            n = malloc(sizeof(struct ListNode));
            n->val = v3;
            n->next = NULL;
        
       if( l3 == NULL ) 
        {
            l3 = n;
            
        }
        else
        {
            l3Tail->next = n;
        }
        
        l3Tail = n;
        
        if(l1)
            l1 = l1->next;
        
        if(l2)
            l2 = l2->next;
    }
    
    if( carry )
    {
        struct ListNode *n = NULL;
        
            n = malloc(sizeof(struct ListNode));
            n->val = carry;
            n->next = NULL;
        
        if( l3 == NULL ) 
        {
            l3 = n;
            
        }
        else
        {
            l3Tail->next = n;
        }
        
        l3Tail = n;
    }
    
    return l3;
    
}