

/**
 *
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
Accepted
1,549,675
Submissions
2,168,961
 

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
    int maxDepth(TreeNode* root) {
        if ( not root ) 
        	return 0;
        return 1 + std::max( maxDepth(root->left), maxDepth(root->right) );
    }
};

int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		TreeNode *n1 = new TreeNode(3);
				  n1->left = new TreeNode(9);
				  n1->right = new TreeNode(20);
				  n1->right->left  = new TreeNode(15);
				  n1->right->right = new TreeNode(7);
		std::cout << " " << s.maxDepth(n1) << "\n";
	}

    return 0;
}