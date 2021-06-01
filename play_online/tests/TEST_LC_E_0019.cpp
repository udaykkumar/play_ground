#include <LC_E_0019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0019 )

BOOST_AUTO_TEST_CASE( deleteDuplicates_Case_1 )
{
	ListNode *l = new ListNode(1);
	l->next = new ListNode(1);
	l->next->next = new ListNode(2);

	lc::deleteDuplicates(l);
	int i = 0;
	int res[] =
	{ 1, 2 };
	for (ListNode *c = l; c; c = c->next)
	{
		BOOST_CHECK(c->val == res[i++]);
	}

}

BOOST_AUTO_TEST_CASE( deleteDuplicates_Case_2 )
{
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);

	{
		ListNode *c = l1;
		for (int i = 2; i < 15; i++)
		{
			c->next = new ListNode(i);
			c = c->next;
			c->next = new ListNode(i);
			c = c->next;
		}
	}

	{
		ListNode *c = l2;
		for (int i = 2; i < 15; i++)
		{
			c->next = new ListNode(i);
			c = c->next;
		}
	}

	l1 = lc::deleteDuplicates(l1);

	for (ListNode *c1 = l1, *c2 = l2; c1 && c2; c1 = c1->next, c2 = c2->next)
	{
		BOOST_CHECK(c1->val == c2->val);
	}

}

BOOST_AUTO_TEST_SUITE_END()

