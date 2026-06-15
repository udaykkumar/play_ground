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
    bool hasCycle(ListNode *head) {
        if ( head == nullptr ) 
            return false;
        
        if ( head->next == nullptr )
            return false;
        
        auto slow = head;
        auto fast = head->next;
        
        for (  ; fast ; slow = slow->next ) {
            
            if ( slow == fast )
                return true;
            
            if ( fast->next and fast->next->next ) 
                fast = fast->next->next;
            else
                return false;
        }
        
        return false;
    }
};