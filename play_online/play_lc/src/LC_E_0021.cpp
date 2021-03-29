#include <LC_E_0021.hpp>

namespace lc
{
bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (p && q)
		return (p->val == q->val) ?
				isSameTree(p->left, q->left) && isSameTree(p->right, q->right) :
				false;

	return (!p && !q);
}
}

