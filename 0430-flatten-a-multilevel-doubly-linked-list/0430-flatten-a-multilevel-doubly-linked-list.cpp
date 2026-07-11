/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL)
            return NULL;

        Node* curr = head;

        while(curr){

            if(curr->child){

                Node* next = curr->next;

                Node* childHead = flatten(curr->child);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // Find tail of child list
                Node* tail = childHead;
                while(tail->next){
                    tail = tail->next;
                }

                // Connect with original next
                tail->next = next;
                if(next){
                    next->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};