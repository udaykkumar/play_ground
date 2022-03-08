/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max( int x , int  y )
{
    return (x > y) ? x : y;
}

int height( struct TreeNode *root ) {
    if( root == NULL )
        return 0;
    return 1 + max( height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode* root) {
    if( root == NULL )
        return true;
    
    return isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left) - height(root->right)) <= 1 ) ;
}