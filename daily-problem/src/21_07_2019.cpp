/*
Hi, here's your problem today. This problem was recently asked by Apple:

Given an integer k and a binary search tree, find the floor (less than or equal to) of k, 
and the ceiling (larger than or equal to) of k. If either does not exist, then print them as None.

Here is the definition of a node for the tree.
class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value

def findCeilingFloor(root_node, k, floor=None, ceil=None):
  # Fill this in.

*/

#include <21_07_2019.hpp>
#include <iostream>

namespace daily_interview
{
	void bst::add(node *&r, const int x)
	{
		if( r == nullptr )
		{
			r = new node(x);
		}
		else if ( x < r->get() )
		{
			add( r->left(), x );
		}
		else if ( x > r->get() )
		{
			add( r->right(), x );
		}
	}

	void bst::show(node* r)
	{
		if( r != nullptr)
		{
			std::cout << " " << r->get();
			show(r->left());
			show(r->right());
		}
	}

	void bst::add(const int x)
	{
		add( root(), x) ;
	}

	void bst::show()
	{
		show(root());
	}

	int bst::floor(const int x)
	{
		node *floor   = root();
		node *crawler = root();
		while( crawler )
		{
			if( x == crawler->get() )
			{
				if( crawler->left() )
				{
					floor = crawler->left();
					while( floor->right() )
						floor = floor->right();
				}
				return floor->get();
			}
			else if( x < crawler->get() )
			{
				floor = crawler;
				crawler = crawler->left();
			}
			else
			{
				floor = crawler;
				crawler = crawler->right();	
			}

		}

		return -1;
	}

	int bst::ceil(const int x)
	{
		node *ceil   = root();
		node *crawler = root();
		while( crawler )
		{
			if( x == crawler->get() )
			{
				if( crawler->right() )
				{
					ceil = crawler->right();
					while( ceil->left() )
						ceil = ceil->left();
				}
				return ceil->get();
			}
			else if( x < crawler->get() )
			{
				ceil = crawler;
				crawler = crawler->left();
			}
			else
			{
				ceil = crawler;
				crawler = crawler->right();	
			}

		}

		return -1;
	}
}