/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* currentNew;
        Node* currentOld=head;
        std:: unordered_map<Node*,Node*> randos;
        while(currentOld){
            currentNew=new Node(currentOld->val);
            randos[currentOld]=currentNew;
            currentOld=currentOld->next;
           
        }
        currentOld=head;
       
         while(currentOld){
            currentNew=randos[currentOld];
            currentNew->next=randos[currentOld->next];
            currentNew->random=randos[currentOld->random];
            currentOld=currentOld->next;
        }
        return randos[head];
    }
};
