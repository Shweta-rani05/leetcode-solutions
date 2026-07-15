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
        ListNode* temp = head;
        int cnt = 0;
        //check if k nodes exist 
        while(cnt < k){
            if(temp ==NULL){
                return head;
            }
            temp = temp->next ;
            cnt ++;
        }
        //recursive call for rest of ll 
        ListNode* prevNode = reverseKGroup(temp ,k);
        //reverse the current group
        temp = head;cnt=0;
        while(cnt < k){
            ListNode* nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
            cnt++;
        }
        return prevNode;
    }
};