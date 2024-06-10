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
    int widthOfBinaryTree(TreeNode* root) { 
        int ans =0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mini=q.front().second;
            int leftEnd;
            int rightEnd;
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int col = (it.second)-mini;
                
                if(i==0) leftEnd = col;
                if(i==size-1) rightEnd = col;

                if(node->left){
                    q.push({node->left, (long long)col*2+1});
                }
                if(node->right){
                    q.push({node->right, (long long)col*2+2});
                }
            }
            ans = max(ans,rightEnd-leftEnd+1);
        }
        return (int)ans;
    }
};