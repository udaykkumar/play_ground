/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       for(ListNode *c = head; c && c->next;  )
            if( c->val == c->next->val )
                c->next = c->next->next;
            else
                c = c->next;
        return head;
    }
};