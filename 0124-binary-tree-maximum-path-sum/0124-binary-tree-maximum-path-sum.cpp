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
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        levelorder(root);
        return maxSum;
    }

    int levelorder(TreeNode* root){
        if(!root) return 0;
        int leftSum = max(0,levelorder(root->left));
        int rightSum = max(0,levelorder(root->right));

        maxSum = max(maxSum,(leftSum+rightSum)+root->val);
        return root->val+max(leftSum,rightSum);
    }
};