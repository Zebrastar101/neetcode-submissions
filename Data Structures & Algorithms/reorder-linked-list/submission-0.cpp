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
    void reorderList(ListNode* head) {
        //vector<ListNode*> vals;
        ListNode* slow=head;
        ListNode* fast= head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast= fast->next->next;
        }
        ListNode* prev = nullptr;   // Tracks the node before the current one
        ListNode* curr = slow->next;      // Tracks the node currently being processed
        slow->next = nullptr;
        ListNode* nextNode = nullptr; // Temporarily stores the rest of the list

        while (curr != nullptr) {
            nextNode = curr->next;  // 1. Save the next node
            curr->next = prev;      // 2. Reverse the current node's link
            prev = curr;            // 3. Move prev one step forward
            curr = nextNode;        // 4. Move curr one step forward
        }
        curr= prev;
        ListNode* star=head;
        
        while(curr){
            ListNode* nextVal=star->next;
            ListNode* nextIndex= curr->next;
            star->next=curr;
            curr->next= nextVal;
            curr=nextIndex;
            star=nextVal;
        }

    }
};
