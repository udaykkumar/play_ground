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
    void dfs( TreeNode *r, int &h, int &mh, int &s )
    {
        if( r )
        {
            h += 1;
            if ( mh < h )
            {
                s = 0;
                mh = h;
                s += r->val;
            }
            else if ( mh == h )
            {
                s += r->val;
            }
            
            if ( r->left )
            {
                dfs(r->left, h, mh, s);
                h--;
            }
            if ( r->right )
            {
                dfs(r->right, h, mh, s);
                h--;    
            }
        }
        return ;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int h = 0, mh = 0,  s = 0;
        dfs(root, h, mh, s);
        return s;
    }
    
};