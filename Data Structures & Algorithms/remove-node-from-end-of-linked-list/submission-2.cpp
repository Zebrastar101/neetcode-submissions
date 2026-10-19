/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return nullptr;
        }
        head=reverse(head);
        ListNode* cur=head;
        ListNode* temp=nullptr;
        while(n>0){
            
            if(n==1){
                 
                if (temp == nullptr) {
                    head = cur->next;
                } else {
                    temp->next = cur->next;
                }
                break;
            
        
            }
            n--;
            temp=cur;
            cur=cur->next;
        }
        return reverse(head);

    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;   // Tracks the node before the current one
        ListNode* curr = head;      // Tracks the node currently being processed
        ListNode* nextNode = nullptr; // Temporarily stores the rest of the list

        while (curr != nullptr) {
            nextNode = curr->next;  // 1. Save the next node
            curr->next = prev;      // 2. Reverse the current node's link
            prev = curr;            // 3. Move prev one step forward
            curr = nextNode;        // 4. Move curr one step forward
        }
        return prev;
    }
};
