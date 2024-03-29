

/**
 *
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <set>
/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if ( !p and !q ) return true;
    	if ( !p and  q ) return false;
    	if (  p and !q ) return false;
		if ( p->val != q->val )
			return false;
		return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};


int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		TreeNode *n1 = new TreeNode(2);
				  n1->left = new TreeNode(1);
				  n1->right = new TreeNode(3);
	
		TreeNode *n2 = new TreeNode(2);
				  n2->left = new TreeNode(1);
				  n2->right = new TreeNode(3);
		std::cout << " " << s.isSameTree(n1,n2) << "\n";
	}

	{
		Solution s;
		TreeNode *n1 = new TreeNode(1);
				  n1->left = new TreeNode(2);
				 
	
		TreeNode *n2 = new TreeNode(1);
				  n2->right = new TreeNode(2);
		std::cout << " " << s.isSameTree(n1,n2) << "\n";
	}
    return 0;
}