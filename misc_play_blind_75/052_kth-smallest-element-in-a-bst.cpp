

/**
 *
Given the root of a binary tree, invert the tree, and return its root.

 
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <set>
/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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

int main(int argc, char const *argv[]) {
    
   
	{
		Solution s;
		TreeNode *n = new TreeNode(2);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(3);
	
		std::cout << " " << s.kthSmallest(n, 2);
		
	}

	{
		Solution s;
		TreeNode *n = new TreeNode(5);
				  n->left = new TreeNode(1);
				  n->right = new TreeNode(9);
						n->right->left = new TreeNode(7);
						n->right->right = new TreeNode(16);
						
		std::cout << " " << s.kthSmallest(n, 3);
	}
    return 0;
}