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
 //Recursive Solution:
 /*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    void postorder(TreeNode* root, vector<int>& ans){
        if(!root){
            return;
        }
        postorder(root -> left, ans);
        postorder(root -> right, ans);
        ans.push_back(root -> val);
    }
};
*/
//Iterative Solution(single stack):  
//                     TC -> O(2N) for each element first inserting, then coming back.
//                     SC -> O(N) inserting atmost N elements into the stack.

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(!st.empty() || cur!= NULL){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
        
                else{
                    cur = st.top()->right;
                }
            }
        }
        return ans;
    }
};
*/

//Iterative Solution(double stack):
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        if(root==NULL){
            return ans;
        }
        
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode* temp=st1.top();
            st1.pop();
            st2.push(temp);


            if(temp->left != NULL){
                st1.push(temp->left);
            }
            if(temp->right != NULL){
                st1.push(temp->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};