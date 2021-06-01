#ifndef __CIRCULAR_SINGLE_LINKED_LIST_HPP_INCLUDED__
#define __CIRCULAR_SINGLE_LINKED_LIST_HPP_INCLUDED__

#include <iostream>

namespace ds
{
struct node
{

	node(int x) :
			d_(x), next_(NULL)
	{
	}

	int d_;
	struct node *next_;
};

struct csll
{

	csll() :
			head_(NULL), sz_(0)
	{
	}
	~csll();

	/* List Operations */
	int add(const int);
	int remove();

	/* Utilities */
	void print(void) const;
	const size_t size() const;
	bool isEmpty(void) const;

	/* Members */
	struct node *head_;
	size_t sz_;
};
}
#endif
