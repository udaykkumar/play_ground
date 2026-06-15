

/**
 *
Given the root of a binary tree, 
return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
Accepted
1,151,756
Submissions
1,907,203
 

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

	int max_depth( TreeNode *r ) {
		if ( not r )
			return 0;
		return 1 + std::max(max_depth( r->left ) , max_depth( r->right ));
	}

	void levelOrder( TreeNode *r, int depth, std::vector< std::vector<int> > &res) {
		if ( not r ) {
			return ;
		}

		res[depth].emplace_back(r->val);
		levelOrder( r->left, depth+1, res);
		levelOrder( r->right, depth+1, res);
	}

public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {

        if ( not root ) return {};

        int depth = max_depth(root);
        std::vector<std::vector<int>> res(depth);

        levelOrder( root, 0, res );
        return res;
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

		auto res = s.levelOrder(n1);
		for ( auto r : res ) {
			std::cout << " { " ;
			for ( auto ri : r ) { std::cout << ri << " " ; }
			std::cout << " } ";
		}
		std::cout << "\n";
	}

    return 0;
}