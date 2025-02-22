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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        vector<pair<int,int>> nodes; 
        int i = 0;
        
        
        while(i<n){
            int depth = 0;
            while(i<n && traversal[i]=='-'){
                depth++;
                i++;
            }
            int value = 0;
            while(i<n && isdigit(traversal[i])){
                value=value*10 + (traversal[i] - '0');
                i++;
            }
            nodes.push_back({depth, value});
        }
        
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(nodes[0].second);
        st.push(root);
        
        for(int j=1; j<nodes.size(); j++){
            int currDepth = nodes[j].first;
            TreeNode* node = new TreeNode(nodes[j].second);
            
            //like, when we go back to the other side of a node, we don't need the left sides nodes anymore
            while(st.size() > currDepth){ 
                st.pop();
            }
            
            TreeNode* parent = st.top();
            if(!parent->left){
                parent->left = node;
            } 
            else{
                parent->right = node;
            }
            st.push(node);
        }
        
        return root;
    }
};