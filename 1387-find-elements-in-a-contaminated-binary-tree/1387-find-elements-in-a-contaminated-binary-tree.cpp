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
class FindElements {
public:
    unordered_map<int, bool> mp;
    FindElements(TreeNode* root) {
        recover(root, 0);
        mp[0] = true;
    }
    void recover(TreeNode* root, int value){
        int currValue = value;
    
        if(root->left){
            root->left->val = 2*currValue + 1;
            mp[2*currValue+1] = true;
            recover(root->left, 2*currValue+1);
        }
        if(root->right){
            root->right->val = 2*currValue + 2;
            mp[2*currValue+2] = true;
            recover(root->right, 2*currValue+2);
        }
    }
    
    bool find(int target) {
        if(mp[target]>=1){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */