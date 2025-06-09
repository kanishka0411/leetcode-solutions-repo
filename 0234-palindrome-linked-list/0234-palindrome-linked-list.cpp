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
    ListNode *reverse(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *newHead=reverse(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *sec=reverse(slow);
        ListNode *fir=head;
        ListNode *temp=sec;

        while(temp){
            if(fir->val!=temp->val){
                reverse(sec);
                return false;
            }
            temp=temp->next;
            fir=fir->next;
        }

        reverse(sec);
        return true;
    }
};