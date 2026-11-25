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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *before=dummy;
        for(int i=0;i<left-1;i++){
            before=before->next;
        }

        ListNode *first=before->next;
        ListNode *temp=first;
        ListNode *prev=nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        before->next=prev;
        first->next=temp;

        return dummy->next;
    }
};