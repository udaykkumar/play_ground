

/**
 *
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

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
    TreeNode* invertTree(TreeNode* root) {
        if ( root ) {
        	/// Typicallyu is it about swapping left and right nodes
        	/// but recursively
        	root->left = invertTree(root->left);
        	root->right= invertTree(root->right);
        	std::swap( root->left , root->right);
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		TreeNode *n = new TreeNode(2);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(3);
	
		auto t = s.invertTree(n);
		
	}

	{
		Solution s;
		TreeNode *n = new TreeNode(5);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(4);
						n->right->left = new TreeNode(3);
						n->right->right = new TreeNode(6);
						
		auto t = s.invertTree(n);
	}
    return 0;
}