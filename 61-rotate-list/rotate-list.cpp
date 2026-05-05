class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        int length = 1;

        while (temp->next) {
            temp = temp->next;
            length++;
        }

        temp->next = head; 

        k = k % length;
        int stepsToNewHead = length - k;

        ListNode* newTail = temp;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};