//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/**
 Given a sorted linked list, delete all duplicates such that each element appear only once.

 Example 1:

 Input: 1->1->2
 Output: 1->2
 Example 2:

 Input: 1->1->2->3->3
 Output: 1->2->3
 **/

#ifndef __LC_E_0019_HPP_INCLUDED__
#define __LC_E_0019_HPP_INCLUDED__
#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr)
	{
	}
};

namespace lc
{

ListNode* deleteDuplicates(ListNode *head);
}

#endif
