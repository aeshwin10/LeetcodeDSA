/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parents[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parents[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root,parents);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_lvl==k) break;
            curr_lvl++;
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]){
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if(parents[current] && !visited[parents[current]]){
                    visited[parents[current]] = true;
                    q.push(parents[current]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};