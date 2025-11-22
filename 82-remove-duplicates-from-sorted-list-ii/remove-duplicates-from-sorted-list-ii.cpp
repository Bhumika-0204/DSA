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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=new ListNode(-1);
        temp->next=head;
        ListNode*prev=temp;
        while(head!=NULL){
            if(head->next!=NULL &&head->val==head->next->val){
                int dup=head->val;
                while(head!=NULL &&head->val==dup){
                    head=head->next;

                }
                prev->next=head;
            }
            else{
                prev=head;
                head=head->next;

            }
        }
        return temp->next;
    }
};