class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
    int dfs(TreeNode* root, long l,long r){
        if(root==nullptr){
            return true;
        }
        if(!(l<root->val&&root->val<r)){
            return false;
        }
        return dfs(root->left,l,root->val)&&dfs(root->right,root->val,r);
    }
};