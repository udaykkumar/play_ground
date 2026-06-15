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
    int kthSmallest(TreeNode* root, int k) {
        
        int i = 1;
        int ret = -1;
        std::function< bool (TreeNode *) >  searchMinK = [&searchMinK, &i, &k, &ret]( TreeNode *root ) -> bool {
        	if ( root ) {
                
                if ( searchMinK(root->left) ) return true;
                
                if ( k == i  ) {
                    ret = root->val;
                    return true;
                }
                
        	    i++;
                
                if ( searchMinK(root->right) ) return true;
            }
            return false;
        };

        searchMinK(root);

        return ret;
    }
};