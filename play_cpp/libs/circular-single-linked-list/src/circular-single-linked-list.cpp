#include "circular-single-linked-list.hpp"

/*Destructor*/
ds::csll::~csll()
{
	// There is a Leak ..TODO
}

/* List Operations */
int ds::csll::add(const int d)
{
	if (isEmpty())
	{
		head_ = new node
		{ d };
		head_->next_ = head_;
	}
	else
	{
		node *c = head_;
		while (c->next_ != head_)
			c = c->next_;

		node *n = new node
		{ d };
		n->next_ = head_;
		c->next_ = n;
	}

	sz_++;
	return 0;
}

int ds::csll::remove()
{
	int ret = -1;
	if (!isEmpty())
	{
		node *c = head_;
		while (c->next_ != head_)
			c = c->next_;

		node *n = c->next_;
		c->next_ = c->next_->next_;
		n->next_ = NULL;
		head_ = c;
		ret = n->d_;
		sz_--;
	}

	return ret;
}

/* Utilities */

void ds::csll::print(void) const
{
	for (node *c = head_; c && (c->next_ != head_); c = c->next_)
		std::cout << c->d_ << " ";
	std::cout << "\n";
}

const size_t ds::csll::size() const
{
	return sz_;
}

bool ds::csll::isEmpty(void) const
{
	return (head_) ? false : true;
}

