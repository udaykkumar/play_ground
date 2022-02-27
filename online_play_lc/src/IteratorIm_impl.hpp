#ifndef __ITERATOR_IM_IMPL_INCLUDED__
#define __ITERATOR_IM_IMPL_INCLUDED__

namespace bira
{
template<typename type_t>
void list<type_t>::push_back(const type_t x)
{
	node *n = new node(x);
	if (!root())
	{
		root() = n;
	}
	else
	{
		node *crawl = root();
		while (crawl->next())
		{
			crawl = crawl->next();
		}
		crawl->next() = n;
	}
	this->size_++;

}

template<typename type_t>
void list<type_t>::push_front(const type_t x)
{
	struct node *n = new node(x);
	n->next() = root();
	root() = n;
	size_++;
}

template<typename type_t>
void list<type_t>::reverse()
{
	node *head = nullptr;
	node *current = nullptr;
	node *crawler = root();
	for (; crawler;)
	{
		current = crawler;
		crawler = crawler->next();
		current->next() = head;
		head = current;
	}
	root() = head;
}

// This should thrown exception saying nothing found
template<typename type_t>
const type_t list<type_t>::back()
{
	if (root())
	{
		node *crawler = root();
		while (crawler->has_next())
		{
			crawler = crawler->next();
		}

		return crawler->get();
	}
	return -1;
}

// This should thrown exception saying nothing found
template<typename type_t>
const type_t list<type_t>::front()
{
	if (root())
	{
		return root()->get();
	}
	return -1;
}

// This should thrown exception saying nothing found
template<typename type_t>
void list<type_t>::pop_back()
{
	//TODO
}

// This should thrown exception saying nothing found
template<typename type_t>
void list<type_t>::pop_front()
{
	if (root())
	{
		node *t = root();
		root() = root()->next();
		t->next() = nullptr;
		delete t;

		size_--;
	}
}

}

#endif
