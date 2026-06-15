#include <Iterator.hpp>

namespace bira
{
void list::add(const int d)
{
	node *n = new node(d);
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

void list::traverse()
{
	for (node *crawl = root(); crawl; crawl = crawl->next())
	{
		//std::cout << crawl->get() << " " << "\n";
	}
}

void list::reverse()
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

} // namespace bira
