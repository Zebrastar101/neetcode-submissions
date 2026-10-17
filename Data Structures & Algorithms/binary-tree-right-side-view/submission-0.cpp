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
 //find size of queue
 //pop through till last on size and pop to queue as u go
 //push last val to result;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        std:: queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        
        while(!q.empty()){
            int len= q.size();
            for(int i=0; i< len;i++){
                if(i==len-1){
                    result.push_back(q.front()->val);
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            
        }
        return result;
    }
};
