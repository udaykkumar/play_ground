/*
Hi, here's your problem today. This problem was recently asked by Twitter:

You are given the root of a binary tree. Invert the binary tree in place. That is, all left children should become right children, and all right children should become left children.

Example:

    a
   / \
  b   c
 / \  /
d   e f

The inverted version of this tree is as follows:

  a
 / \
 c  b
 \  / \
  f e  d

Here is the function signature:

class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.value = value
  def preorder(self):
    print self.value,
    if self.left: self.left.preorder()
    if self.right: self.right.preorder()

def invert(node):
  # Fill this in.

root = Node('a') 
root.left = Node('b') 
root.right = Node('c') 
root.left.left = Node('d') 
root.left.right = Node('e') 
root.right.left = Node('f') 

root.preorder()
  5 3 2 4 7 6
# a b d e c f 
print "\n"
invert(root)
root.preorder()
# a c f b e d
  5 7 6 3 4 2
*/

#include <22_07_2019.hpp>
#include <iostream>



namespace daily_interview
{
	void binary_tree::add(node *&r, int x)
	{
		if( r == nullptr )
		{
			r = new node(x);
			return;
		}
		else if( x < r->get() )
		{
			add( r->left(), x);
		}
		else if( x > r->get() )
		{
			add( r->right(), x);
		}
	}

	void binary_tree::add(int x)
	{
		add(root(),x);
	}


	void binary_tree::show( node* r)
	{
		if( r != nullptr)
		{
			show(r->left());
			std::cout << r->get() << " ";
			show(r->right());
		}
		
	}

	void binary_tree::show()
	{
		std::cout << "\n";
		show(root());		
		std::cout << "\n";
	}


	void binary_tree::invert(node *r)
	{
		if(r)
		{
			invert(r->left());
			invert(r->right());

			node *t    = r->left();
			r->left()  = r->right();
			r->right()  = t;
		}
	}
	
	void binary_tree::invert()
	{
		invert(root());
	}
	
}