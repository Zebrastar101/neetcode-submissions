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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int left= maxDepth(root->left);
        int right = maxDepth(root->right);
        int sub= left-right;
        if(sub<=1 &&sub>=-1){
            return isBalanced(root->left) && isBalanced(root->right);;
        }
        return false;
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        
    }
};
