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
    ListNode *rev(ListNode *node){
        ListNode *temp=node;
        ListNode *prev=nullptr;
        while(temp!=nullptr){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *second=rev(slow->next);
        slow->next=nullptr;
        ListNode *first=head;
        while(second!=nullptr){
            ListNode *front1=first->next;
            ListNode *front2=second->next;
            first->next=second;
            second->next=front1;
            first=front1;
            second=front2;

        }

    }
};