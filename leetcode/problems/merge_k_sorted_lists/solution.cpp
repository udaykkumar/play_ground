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