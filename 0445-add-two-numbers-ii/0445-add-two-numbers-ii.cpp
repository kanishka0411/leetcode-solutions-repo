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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rev1=rev(l1);
        ListNode *rev2=rev(l2);
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        while(rev1!=nullptr || rev2!=nullptr || carry){
            int sum=0;
            if(rev1!=nullptr){
                sum+=rev1->val;
                rev1=rev1->next;
            }
            if(rev2!=nullptr){
                sum+=rev2->val;
                rev2=rev2->next;
            }
            sum+=carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
        }
        ListNode *node=rev(dummy->next);
        return node;
    }
};