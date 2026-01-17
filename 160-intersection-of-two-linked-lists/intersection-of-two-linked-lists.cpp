/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getlength(ListNode*head){
        int len=0;;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL ||headB==NULL) return NULL;
        int lenA=getlength(headA);
        int lenB=getlength(headB);
        ListNode*p1=headA;
        ListNode*p2=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            while(diff--) p1=p1->next;
        }else{
            int diff=lenB-lenA;
            while(diff--) p2=p2->next;
        }
        while(p1!=NULL &&p2!=NULL){
            if(p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
    }
};