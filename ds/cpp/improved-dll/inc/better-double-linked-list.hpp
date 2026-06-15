#ifndef __BETTER_DOUBLE_LINKED_LIST_HPP_INCLUDED__
#define __BETTER_DOUBLE_LINKED_LIST_HPP_INCLUDED__

#include <iostream>

namespace ds
{
struct node
{

	node(int x) :
			d_(x), next_(NULL), prev_(NULL)
	{
	}

	int d_;
	struct node *next_, *prev_;
};

struct betterdll
{

	betterdll() :
			head_(NULL), tail_(NULL), sz_(0)
	{
	}
	~betterdll();

	/* List Operations */
	int addHead(const int);
	int addTail(const int);
	int addAtPosition(const int, size_t);

	int removeHead();
	int removeTail();
	int removeAtPosition(size_t);

	/* Utilities */
	void print(void) const;
	const size_t size() const;
	bool isEmpty(void) const;

	/* Members */
	struct node *head_, *tail_;
	size_t sz_;
};
}
#endif
