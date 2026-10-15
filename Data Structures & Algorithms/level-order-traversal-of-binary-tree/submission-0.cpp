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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root){
            return result;
        }
        std:: queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        //TreeNode* cur=q.front();
        
        while(!q.empty()){
            int level=q.front().second;
            if(level==result.size()){
                result.push_back({});
            }
            TreeNode* cur=q.front().first;
            result[level].push_back(cur->val);
            q.pop();
            
            if(cur->left){
                q.push({cur->left,level+1});
            }
            if(cur->right){
                q.push({cur->right,level+1});
            }
            
        }
        return result;
        
    }
};
