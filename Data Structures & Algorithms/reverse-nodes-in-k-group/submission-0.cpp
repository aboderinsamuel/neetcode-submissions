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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //step1 : check if there are at least K nodes left
        ListNode* node = head;
        int count = 0;
        while(node && count < k){
            node = node->next;
            count++;
        }
        if(count < k) return head;

        //step2 : reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i=0; i<k; i++){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // step3 : recursively reverse the rest, then connect head, is now the tail of this reversed group
        head->next = reverseKGroup(curr, k);
        return prev;
        
    }
};
