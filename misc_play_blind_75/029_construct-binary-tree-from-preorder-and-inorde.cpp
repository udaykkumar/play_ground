

/**
 *
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

    	int ri = 0;
    	std::function < TreeNode *(int ,int ) > make_tree = [&make_tree, &preorder, &inorder, &ri]
    			( int si, int ei ) -> TreeNode * {
		    		/// Break recursion
					if ( si > ei ) return nullptr;
					
					/// by default the start is pivot
					int p = si;

					/// unless we find where the pivior is .. 
					while ( inorder[p] != preorder[ri] ) p++;

					/// we move our root ... this is the root of preorder array
					/// every recusrive call increments the root index
					/// by the time this executed we must have traversed 
					/// all nodes in left subtree and that is why we pass by reference
					
					ri ++;
					return new TreeNode(inorder[p], 
									make_tree( si, p-1 ),
									make_tree(p+1, ei  ));
    	};

    	return make_tree( 0, preorder.size()-1);
    }

    void print_inorder(TreeNode *r) {
    	if ( r ) {
    		print_inorder(r->left);
    		std::cout << " " << r->val ;
    		print_inorder(r->right);
    	}
    }
};


int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		std::vector preorder {3,9,20,15,7};
		std::vector inorder  {9,3,15,20,7};

		TreeNode *n = s.buildTree(preorder, inorder);
		std::cout << "out : ";
		s.print_inorder(n);
		std::cout << "\n";
	}

	{
		Solution s;
		std::vector preorder {-1};
		std::vector inorder  {-1};

		TreeNode *n = s.buildTree(preorder, inorder);
		std::cout << "out : ";
		s.print_inorder(n);
		std::cout << "\n";
	}
    return 0;
}