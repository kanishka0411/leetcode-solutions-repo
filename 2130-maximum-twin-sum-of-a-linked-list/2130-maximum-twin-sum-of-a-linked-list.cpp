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
    int pairSum(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *first=head;
        ListNode *second=rev(slow);
        int maxi=0;
        while(second!=nullptr && first!=nullptr){
            int sum=second->val + first->val;
            maxi=max(maxi,sum);
            first=first->next;
            second=second->next;
        }
        return maxi;
    }

    
};