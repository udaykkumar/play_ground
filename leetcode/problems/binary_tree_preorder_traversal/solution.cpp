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
    void crawl( TreeNode *r, vector<int> &v)
    {
        if ( r )
        {
            v.emplace_back(r->val);
            crawl(r->left, v);
            crawl(r->right, v);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
            crawl(root, v);
        return v;
    }
};