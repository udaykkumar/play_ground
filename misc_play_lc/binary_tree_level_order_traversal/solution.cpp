/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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