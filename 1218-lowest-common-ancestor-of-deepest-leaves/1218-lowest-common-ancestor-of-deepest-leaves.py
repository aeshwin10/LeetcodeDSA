# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
                                
        def dfs(node = root, level = 0):
            if not node:
                return level-1
            
            l, r = dfs(node.left, level+1), dfs(node.right, level+1)
            
            if l == r:
                d[l] = node
                
            return max(l,r)
        

        d = {}
        return d[dfs()]
        