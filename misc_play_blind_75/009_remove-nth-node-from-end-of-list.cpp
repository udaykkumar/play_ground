/**
 * 
 Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
**/

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

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main(int argc, char const *argv[])
{
	{
		Solution s;
		ListNode *n = new ListNode(1);
				  n->next = new ListNode(2);
				  n->next->next = new ListNode(3);
				  n->next->next->next = new ListNode(4);
				  n->next->next->next->next = new ListNode(5);

		ListNode *nn = s.removeNthFromEnd(n, 2);
		while ( nn ) {
			std::cout << nn->val << " ";
			nn = nn->next;
		}
		std::cout << "\n";
	}

	{
		Solution s;
		ListNode *n = new ListNode(1);
				  n->next = new ListNode(2);
				  n->next->next = new ListNode(3);
				  n->next->next->next = new ListNode(4);
				  n->next->next->next->next = new ListNode(5);

		ListNode *nn = s.removeNthFromEnd(n, 1);
		while ( nn ) {
			std::cout << nn->val << " ";
			nn = nn->next;
		}
		std::cout << "\n";
	}

	{
		Solution s;
		ListNode *n = new ListNode(1);
				  n->next = new ListNode(2);
				  n->next->next = new ListNode(3);
				  n->next->next->next = new ListNode(4);
				  n->next->next->next->next = new ListNode(5);

		ListNode *nn = s.removeNthFromEnd(n, 5);
		while ( nn ) {
			std::cout << nn->val << " ";
			nn = nn->next;
		}
		std::cout << "\n";
	}
	return 0;
}