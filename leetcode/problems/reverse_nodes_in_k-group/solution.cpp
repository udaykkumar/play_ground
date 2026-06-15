/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = nullptr;
        ListNode *cres = nullptr;
      
        while( head )
        {
            ListNode *kres = nullptr;
            // By the end of this Block we'll have a kres
            // which is a sublist based on reverse or not reverse
            // what ever .. this question says ... who creates these
            {
                int i = 0;
                for(  ; (i < k) && head ; i ++)
                {
                    // default we reverse it 
                    ListNode *c = head;
                        head = head->next;
                        c->next = kres;
                        kres = c;
                }
                
                // there is a chance here that the list truncated 
                // in which case we need revert and make it normal
                if ( head == nullptr ) 
                {
                    // but wait if k == i then its in line 
                    // we don't need to do anything
                    if ( i < k )
                    {
                        ListNode *r = nullptr;
                        for ( ; kres ; )
                        {
                            ListNode *c = kres;
                                    kres = kres->next;
                                    c->next = r;
                                    r = c;
                        }
                        
                        // phew ..
                        kres = r;
                    }
                }
            }
            
            
            if ( res == nullptr )
            {
                res = kres;
                cres = kres;
            } 
            else 
            {
                cres->next = kres;
            }
            
            while ( cres->next )
                cres = cres->next;
            
        }
        
        return res;
    }
};