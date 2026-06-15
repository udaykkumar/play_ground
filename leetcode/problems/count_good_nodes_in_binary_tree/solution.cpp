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
    
    int gn( TreeNode *t, int m )
    {
        if (t) {
            int yesNo = ( t->val >= m ) ? 1 : 0;
            int mx    = std::max( t->val, m);
            return yesNo + gn( t->left, mx) + gn( t->right, mx);
        }
        return 0;
    }
    
public:
    int goodNodes(TreeNode* root) {
        return root ? gn( root, root->val ) : 0;
    }
};