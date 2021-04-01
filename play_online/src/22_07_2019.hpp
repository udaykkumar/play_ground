#ifndef __22_07_2019_HPP_INCLUDED__
#define __22_07_2019_HPP_INCLUDED__

namespace daily_interview
{
struct binary_tree
{
private:
	struct node
	{

		int x_;
		struct node *left_;
		struct node *right_;

		node(int x) :
				x_(x), left_(nullptr), right_(nullptr)
		{
		}

		node*& left()
		{
			return left_;
		}
		node*& right()
		{
			return right_;
		}
		int get()
		{
			return x_;
		}

	};

	struct node *root_;
	void add(node*&, int);
	void show(node*);
	void invert(node*);

public:
	binary_tree() :
			root_(nullptr)
	{
	}

	void add(int x);
	void show();
	void invert();
	node*& root()
	{
		return root_;
	}
};
}
#endif
