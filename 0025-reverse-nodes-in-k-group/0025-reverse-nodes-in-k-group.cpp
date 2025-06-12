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
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=nullptr){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prevHead=dummy;
        ListNode *temp=head;
        ListNode *start=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            if(cnt==k){
                ListNode *nextHead=temp->next;
                temp->next=nullptr;
                ListNode *newHead=reverse(start);
                prevHead->next=newHead;
                start->next=nextHead;
                prevHead=start;
                start=nextHead;
                temp=nextHead;
                cnt=0;

            }else{
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};