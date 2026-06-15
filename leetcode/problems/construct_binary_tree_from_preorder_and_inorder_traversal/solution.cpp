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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

    	int ri = 0;
    	std::function < TreeNode *(int ,int ) > make_tree = 
            [&make_tree, &preorder, &inorder, &ri]
    			( int si, int ei ) -> TreeNode * {
		    		/// Break recursion
					if ( si > ei ) return nullptr;
					
					/// by default the start is pivot
					int p = si;

					/// unless we find where the pivior is .. 
					while ( inorder[p] != preorder[ri] ) p++;

					/// we move our root ... this is the root of preorder array
					/// every recusrive call increments the root index
					/// by the time this executed we must have traversed 
					/// all nodes in left subtree and that is why we pass by reference
					
					ri ++;
					return new TreeNode(inorder[p], 
									make_tree( si, p-1 ),
									make_tree(p+1, ei  ));
    	};

    	return make_tree( 0, preorder.size()-1);
    }
};