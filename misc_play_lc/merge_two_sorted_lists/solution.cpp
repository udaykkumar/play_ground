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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	
        /// Most basic validations 
        if ( not list1 )  return list2;
        if ( not list2 )  return list1;	
       
        ListNode *mlist = nullptr, *mtail = nullptr;
        while (list1 and list2) {

        	/// find list with smallest node
        	/// get it and advance that list
        	ListNode *n = nullptr;
        	if ( list1->val < list2->val ) {
        		n = list1;
        		list1 = list1->next;
        	} else {
        		n = list2;
        		list2 = list2->next;
        	}

        	
        	/// detach that node
        	n->next = nullptr;

        	/// attach it to mlist;
        	if ( mlist == nullptr ) {
        		mlist = n;
        		mtail = n;
        	} else {
        		mtail->next = n;
                mtail       = mtail->next;
        	}

        }

        if ( list1 ) {
        	mtail->next = list1;
        }
        if ( list2 ) {
        	mtail->next = list2;
        }

        return mlist;
    }
};