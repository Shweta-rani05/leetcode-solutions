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
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mapping; // Stores original-to-clone node mapping

        Node* current = head;
        // First pass: Create new nodes without linking them
        while (current) {
            mapping[current] = new Node(current->val);
            current = current->next;
        }

        // Second pass: Establish next and random pointers
        current = head;
        while (current) {
            mapping[current]->next = mapping[current->next];
            mapping[current]->random = mapping[current->random];
            current = current->next;
        }

        return mapping[head]; // Return deep copy head
    }
};




