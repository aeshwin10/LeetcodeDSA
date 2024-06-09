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

 //Iterative Solution(Own solution) (195/199 test cases passed.)
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        bool ans = true;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int col = it.second;
                sum+=((node->val)*col);

                if(node->left){
                    q.push({node->left,-1});
                }
                if(node->right){
                    q.push({node->right,+1});
                }
            }
            if(sum!=0){
                ans = false;
                break;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || SymmetryCheck(root->left,root->right);
    }
    bool SymmetryCheck(TreeNode* left, TreeNode* right){
        if(left==NULL || right==NULL){
            return (left==right);
        }
        if(left->val!=right->val){
            return false;
        }
        return (SymmetryCheck(left->left,right->right)&&SymmetryCheck(left->right,right->left));
    }
};