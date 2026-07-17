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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Effective rotations
        k = k % n;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;

        while (steps--) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};