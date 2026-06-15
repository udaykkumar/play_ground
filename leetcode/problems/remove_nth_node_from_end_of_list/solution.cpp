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

	int list_size(ListNode* head) {
		int size = 0;
        for ( auto crawl = head; crawl ; crawl = crawl->next )
        	size ++;
        return size;
	}

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /// Get the size first
        int size = list_size(head);

        /// we can't go beyond size 
    	if ( n > size ) return head;

    	/// if n == size means we are asked to delete head
    	/// lets do memory leak intentionally
    	if ( n == size )
    		return head->next;
    	
    	/// we try and point to one less that the node we want
    	ListNode *t = head;
    	for ( int i = 1; i < size-n ; i ++ ) { t = t->next; }

    	/// Introduce memory leak intentionally
    	t->next = t->next->next;
    	return head;
    }
};
