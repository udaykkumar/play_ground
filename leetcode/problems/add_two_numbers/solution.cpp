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
    
    int Get( ListNode * n )
    {
        return n ? n->val : 0;
    }
    
    ListNode* Next(ListNode * n)
    {
        return n ? n->next : n; 
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *h = new ListNode();
        ListNode *c = h;
        int carry = 0;
        
        for ( ; l1 or l2 or carry ; l1 = Next(l1),  l2 = Next(l2), c = Next(c) )  {
            int s = Get(l1) + Get(l2) + carry;
                carry = s/10;
             c->next = new ListNode(s%10);
        }
        
       return h->next ;
    }
};