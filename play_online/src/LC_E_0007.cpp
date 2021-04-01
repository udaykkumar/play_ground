#include <LC_E_0007.hpp>

namespace lc
{
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *l = nullptr, *c = nullptr;
	if (l1 == nullptr && l2 == nullptr)
		return nullptr;

	if (l1 == nullptr)
		return l2;

	if (l2 == nullptr)
		return l1;

	while (l1 && l2)
	{
		ListNode *n = nullptr;
		if (l1->val < l2->val)
		{
			n = l1;
			l1 = l1->next;
		}
		else
		{
			n = l2;
			l2 = l2->next;
		}
		n->next = nullptr;

		if (l == nullptr)
		{
			l = n;
			c = n;
		}
		else
		{
			c->next = n;
			c = c->next;
		}

	}

	if (l1)
		c->next = l1;

	if (l2)
		c->next = l2;

	return l;
}
}

