#ifndef __CTCI_E6_CHAPTER_2_HXX__
#define __CTCI_E6_CHAPTER_2_HXX__
#include <iostream>

namespace ctci6e
{
namespace chapter2
{
struct node
{
	int data_;
	struct node *next_;

	node(int x) :
			data_(x), next_( NULL)
	{
	}

	int get() const
	{
		return data_;
	}

};

struct list
{

private:
	struct node *head;
	size_t list_size;

public:

	/* Ctor */
	list() :
			head( NULL), list_size(0)
	{
	}

	/* List add/del */

	// adds to Head
	struct list* add(int);

	// adds to tail
	struct list* append(int);

	/* search and find and family */
	bool exists(int);

	/* List Meta */
	size_t size() const;

	/* Miscellaneous */
	void show();

	/* Tests */

	/* 2.1 */
	struct list* remove_dups();

	/* 2.2 */
	struct list* return_kth_to_last(const size_t);

	/* 2.3 */
	struct list* delete_middle_node();

	/* 2.4 */
	struct list* partition(int);

};
}
}
#endif
