/**
 * 
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 
 
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
#include <vector>
#include <queue>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {

    	/// we use this priority queue to get the least element
    	auto cmp  = [] ( const ListNode *x, const ListNode *y ) {
    		return x->val > y->val;
    	};
		std::priority_queue< ListNode *, std::vector<ListNode*> , decltype(cmp) > pq(cmp);

    	/// sanitize and push to PQ - its likely we receive nullptrs
    	for ( auto l : lists ) {
    		if ( l ) pq.push(l);
    	}

    	/// Actual merge process starts now
    	ListNode *merged = nullptr, *current = nullptr;
    	while ( pq.size() > 0 ) {

    		/// Get the top and immediately remove from PQ
    		auto top = pq.top(); pq.pop();
    		
    		/// attach this top to merged list.. 
    		/// either at head or at tail
    		if ( not merged ) {
    			merged = top;
    			current = merged;
    		} else {
    			current->next = top;
    			current = current->next;
    		}

    		/// if its last no need to add to PQ
    		if( top->next)
    			pq.push(top->next);
    	}

    	/// Done
        return merged;
    }
};

#define MAKE_LIST(x) 													\
		ListNode *n##x = new ListNode(x);								\
				  n##x->next = new ListNode(x*10);						\
				  n##x->next->next = new ListNode(x*20);				\
				  n##x->next->next->next = new ListNode(x*30);			\
				  n##x->next->next->next->next = new ListNode(x*40);		

#define LIST_NAME(x) n##x
int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::vector< ListNode * > lists;
		MAKE_LIST(1)
		lists.push_back( LIST_NAME(1) );
		
		MAKE_LIST(2)
		lists.push_back( LIST_NAME(2) );

		MAKE_LIST(3)
		lists.push_back( LIST_NAME(3) );
		
		MAKE_LIST(4)
		lists.push_back( LIST_NAME(4) );
		
		MAKE_LIST(5)
		lists.push_back( LIST_NAME(5) );
		
		MAKE_LIST(6)
		lists.push_back( LIST_NAME(6) );
		
		auto nn = s.mergeKLists(lists);
		while ( nn ) {
			std::cout << nn->val << " ";
			nn = nn->next;
		}

	}

	
	return 0;
}