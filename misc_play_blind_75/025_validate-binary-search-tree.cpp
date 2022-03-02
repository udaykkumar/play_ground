

/**
 *
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

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

	bool isValidBST( TreeNode *root, TreeNode *lo, TreeNode *hi) {
		if ( not root ) return true;
		if ( lo and root->val <= lo->val ) return false;
		if ( hi and root->val >= hi->val ) return false;
		/// if we go to left root is hi and if we go right root is lo
		return isValidBST(root->left, lo, root) and isValidBST(root->right, root, hi);
	}

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST( root, nullptr, nullptr) ;
    }
};


int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		TreeNode *n = new TreeNode(2);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(3);
	
		std::cout << " " << s.isValidBST(n) << "\n";
	}

	{
		Solution s;
		TreeNode *n = new TreeNode(5);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(4);
						n->right->left = new TreeNode(3);
						n->right->right = new TreeNode(6);
						
		std::cout << " " << s.isValidBST(n) << "\n";
	}
    return 0;
}