# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __crawlInOrder( self, root: TreeNode, out : List[int] ) :
        if root:
            if root.left:
                self.__crawlInOrder(root.left, out)
            out.append( root.val)
            #print(out)
            self.__crawlInOrder(root.right, out)
            
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        out = []
        self.__crawlInOrder(root, out)
        return out