/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 
 
    1
   / \
  2   2
 / \ / \
3  4 4  3

 */


bool areSymmetric( struct TreeNode *root1, struct TreeNode * root2)
{
    if( root1 == NULL && root2 == NULL )
        return true;
    
    if( root1 && root2 && root1->val == root2->val )
        return areSymmetric(root1->left , root2->right) && areSymmetric( root1->right, root2->left);
    
    return false;
}
bool isSymmetric(struct TreeNode* root) {
    return areSymmetric( root, root );
}