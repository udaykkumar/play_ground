//https://leetcode.com/problems/merge-two-sorted-lists/
/*
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

 Example:

 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */
#ifndef __LC_E_0007_HPP_INCLUDED__
#define __LC_E_0007_HPP_INCLUDED__
#include <iostream>
namespace lc
{
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr)
	{
	}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
}

#endif
