/**
 * 
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 
 
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

int main(int argc, char const *argv[])
{
	{
		Solution s;
		ListNode *n1 = new ListNode(1);
				  n1->next = new ListNode(20);
				  n1->next->next = new ListNode(30);
				  n1->next->next->next = new ListNode(40);
				  n1->next->next->next->next = new ListNode(50);

		

		ListNode *n2 = new ListNode(5);
				  n2->next = new ListNode(15);
				  n2->next->next = new ListNode(35);
				  n2->next->next->next = new ListNode(45);
				  n2->next->next->next->next = new ListNode(55);
		

		ListNode *nn = s.mergeTwoLists(n1, n2);
		while ( nn ) {
			std::cout << nn->val << " ";
			nn = nn->next;
		}
		std::cout << "\n";
	}

	
	return 0;
}