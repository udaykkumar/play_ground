/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        if ( o and c )
        {
            if ( o->val == c->val and o->val == t->val )
                return c;
            if ( auto yes = getTargetCopy(o->left, c->left, t) )
                return yes;
            return getTargetCopy(o->right, c->right, t);
        }
        return nullptr;
    }
};