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
    
    int d_;
    
    int height( TreeNode *n )
    {
        if(n == nullptr)
            return 0;
        
        int l = height( n->left );
        int r = height( n->right );
        d_ = std::max( d_, l+r);
        return std::max(l,r) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        d_ = 0;
        height(root);
        return d_;
    }
};