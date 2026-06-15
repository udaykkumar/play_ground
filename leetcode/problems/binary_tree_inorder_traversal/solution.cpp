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
    
    void inorder( TreeNode *r, std::vector<int> &l ) {
        if ( r ) {
            inorder(r->left, l);
            l.emplace_back(r->val);
            inorder(r->right, l);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ilist;
        inorder( root, ilist);
        return ilist;
    }
};