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