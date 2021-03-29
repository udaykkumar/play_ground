#include "chapter_2.hxx"

namespace ctci6e
{
namespace chapter2
{

struct list* list::add(int x)
{

	if (head == NULL)
	{
		head = new node(x);
	}
	else
	{
		node *n = new node(x);
		n->next_ = head;
		head = n;
	}

	list_size++;
	return this;
}

struct list* list::append(int x)
{

	if (head == NULL)
	{
		head = new node(x);
	}
	else
	{
		node *c = head;
		while (c->next_)
		{
			c = c->next_;
		}
		c->next_ = new node(x);
	}

	list_size++;
	return this;
}

size_t list::size() const
{
	return list_size;
}

bool list::exists(int x)
{
	for (node *c = head; c; c = c->next_)
	{
		if (c->data_ == x)
		{
			return true;
		}
	}
	return false;
}

void list::show()
{
	for (node *c = head; c; c = c->next_)
	{
		std::cout << c->get() << " ";
	}

	std::cout << std::endl;
}

struct list* list::remove_dups()
{

	if (this->size() == 0)
		return this;

	node *current = head;

	/* loop untill current is the last node */
	while (current && current->next_)
	{

		/* Previous is current node */
		node *prev = current;

		/* dup is next to current node */
		node *dup = current->next_;

		/* so we need to traverse these prev and dup till End of list */
		/* if dup is the last node prev is last but one */
		while (dup /* && dup->next_ */)
		{

			if (dup->get() != current->get())
			{
				prev = prev->next_;
				dup = dup->next_;
			}
			else
			{
				/* we have a duplicate */
				node *t = dup;

				prev->next_ = dup->next_;
				dup = dup->next_;

				t->next_ = NULL;
				delete t;

				list_size--;
			}
		}

		/* We can do this for all other remaining nodes */
		current = current->next_;
	}
	return this;
}

struct list* list::return_kth_to_last(const size_t k)
{

	if (this->size() == 0)
	{
		return NULL;
	}

	node *kth_node = head;
	for (size_t i = 0; kth_node && (i < k); i++)
	{
		kth_node = kth_node->next_;
	}

	if (kth_node == NULL)
	{
		return NULL;
	}

	struct list *list = new ctci6e::chapter2::list();
	while (kth_node)
	{
		list->append(kth_node->get());
		kth_node = kth_node->next_;
	}

	return list;
}

struct list* list::delete_middle_node()
{
	if (this->size() <= 2)
		return this;

	size_t node_to_be_deleted = this->size() / 2;

	node *c = head;
	node *p = c;
	c = c->next_;
	for (size_t i = 1; c && (i < node_to_be_deleted); i++)
	{
		p = p->next_;
		c = c->next_;
	}

	p->next_ = c->next_;
	c->next_ = NULL;
	list_size--;
	delete c;
	return this;
}

struct list* list::partition(int x)
{
	node *current = head;
	head = NULL;

	node *pivot;
	while (current)
	{
		/* First thing first detach this node */
		node *t = current;
		current = current->next_;
		t->next_ = NULL;

		if (head == NULL)
		{
			head = t;
			pivot = head;

		}
		else
		{

			if (t->get() < x)
			{
				t->next_ = head;
				head = t;
			}
			else
			{
				t->next_ = pivot->next_;
				pivot->next_ = t;
			}
		}
	}

	return this;
}

}
}
