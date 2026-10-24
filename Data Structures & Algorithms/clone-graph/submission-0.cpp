/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
       unordered_map<Node*,Node*> vals;
       return dfs(node,vals); 
    }
    Node* dfs(Node* node, unordered_map<Node*,Node*>& vals){
        if(!node){
            return nullptr;
        }
        if(vals.contains(node)){
            return vals[node];
        }
        Node* new_node= new Node(node->val);
        vals[node]=new_node;
        for( int i=0; i< node->neighbors.size();i++){
            new_node->neighbors.push_back(dfs(node->neighbors[i],vals));
        }
        return new_node;
    }
};
