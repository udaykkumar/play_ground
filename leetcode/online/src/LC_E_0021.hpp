//https://leetcode.com/problems/same-tree/
/**
 100. Same Tree
 Easy

 1680

 50

 Add to List

 Share
 Given two binary trees, write a function to check if they are the same or not.

 Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

 Example 1:

 Input:     1         1
 / \       / \
         2   3     2   3

 [1,2,3],   [1,2,3]

 Output: true
 Example 2:

 Input:     1         1
 /           \
         2             2

 [1,2],     [1,null,2]

 Output: false
 Example 3:

 Input:     1         1
 / \       / \
         2   1     1   2

 [1,2,1],   [1,1,2]

 Output: false
 **/
#ifndef __LC_E_0021_HPP_INCLUDED__
#define __LC_E_0021_HPP_INCLUDED__
#include <iostream>
namespace lc
{
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr)
	{
	}

};

bool isSameTree(TreeNode *p, TreeNode *q);
}

#endif
