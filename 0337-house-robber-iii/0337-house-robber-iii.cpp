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
    void dfs(TreeNode* curr, unordered_map<TreeNode*, unordered_map<bool, int>>& dp){
        if(!curr){
            return;
        }
        dp[curr][0] = 0;
        dp[curr][1] = curr->val;
        if(curr->left){
            dfs(curr->left, dp);
            dp[curr][0] += max(dp[curr->left][1], dp[curr->left][0]);
            dp[curr][1] += dp[curr->left][0];
        }
        if(curr->right){
            dfs(curr->right, dp);
            dp[curr][0] += max(dp[curr->right][1], dp[curr->right][0]);
            dp[curr][1] += dp[curr->right][0];
        }
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, unordered_map<bool, int>> dp;
        dfs(root, dp);
        return max(dp[root][0], dp[root][1]);
    }
};