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
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *t =  nullptr;
        if ( t1 && t2 )
        {
            t = new TreeNode ( t1->val + t2->val );
            t->left = mergeTrees( t1->left, t2->left );
            t->right = mergeTrees( t1->right, t2->right );
        }
        else if ( t1 )
        {
            t = new TreeNode ( t1->val ) ;
            t->left = mergeTrees( t1->left, nullptr );
            t->right = mergeTrees( t1->right, nullptr );           
        }
        else if ( t2 )
        {
            t = new TreeNode ( t2->val ) ;
            t->left = mergeTrees( nullptr, t2->left );
            t->right = mergeTrees( nullptr, t2->right );
        }
        
        return t;
    }
};