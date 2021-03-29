#include <16_07_2019.hpp>

void list::add(const int data)
{
	node *n = new node(data);
	if (root() == nullptr)
	{
		root() = n;
	}
	else
	{
		node *crawler = root();
		while (crawler->has_next())
		{
			crawler = crawler->next();
		}
		crawler->next() = n;
	}

	this->size_++;
}

void list::traverse()
{
	for (node *crawler = root(); crawler; crawler = crawler->next())
		std::cout << " " << crawler->get() << " ";
	std::cout << "\n";
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
