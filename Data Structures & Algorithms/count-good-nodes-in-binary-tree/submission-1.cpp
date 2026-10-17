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
    int goodNodes(TreeNode* root) {
        int max=root->val;
        
        return dfs(root,max);
    }
    int dfs(TreeNode* root, int max){
        if(root==nullptr){
            return 0;
        }
        if(max<=root->val){
            max=root->val;
            return dfs(root->left,max)+dfs(root->right,max)+1;
        }
        return dfs(root->left,max)+dfs(root->right,max);
    }
};
