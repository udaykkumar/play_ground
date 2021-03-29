/*
 Hi, here's your problem today. This problem was recently asked by Apple:

 You are given two singly linked lists. The lists intersect at some node. Find, and return the node. Note: the lists are non-cyclical.

 Example:

 A = 1 -> 2 -> 3 -> 4
 B = 6 -> 3 -> 4

 This should return 3 (you may assume that any nodes with the same value are the same node).
 */
#include <02_08_2019.hpp>
#include <set>
namespace daily_interview
{

void list::add(const size_t data)
{
	if (head_ == nullptr)
	{
		head_ = new node(data);
	}
	else
	{
		struct node *n = new node(data);
		n->next() = head_;
		head_ = n;
	}
}

void list::show()
{
	for (struct node *crawler = head_; crawler; crawler = crawler->next())
		std::cout << crawler->get() << " ";
	std::cout << "\n";
}

size_t intersection(struct list &list1, struct list &list2)
{
	std::set<size_t> umap;
	struct node *l1_head = list1.head_;
	struct node *l2_head = list2.head_;

	while (l1_head)
	{

		if (umap.find(l1_head->get()) == umap.end())
			umap.insert(l1_head->get());

		l1_head = l1_head->next();
	}

	while (l2_head)
	{
		if (umap.find(l2_head->get()) != umap.end())
			return l2_head->get();

		l2_head = l2_head->next();
	}

	return 0;
}
}

