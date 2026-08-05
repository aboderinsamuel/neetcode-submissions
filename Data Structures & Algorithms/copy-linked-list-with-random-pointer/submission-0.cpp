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
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> oldToNew;

        Node* curr = head;

        while(curr != nullptr){
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr){
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = (curr->random != nullptr) ? oldToNew[curr->random] : nullptr;
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
