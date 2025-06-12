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
    ListNode *findKthNode(ListNode *head,int len){
        ListNode *temp=head;
        int cnt=1;
        while(temp!=nullptr){
            if(cnt==len) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode *tail=head;
        int len=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            len++;
            
        }
        tail->next=head;
        if(k%len==0){
            tail->next=nullptr;
            return head;
        } 
        k=k%len;
        ListNode *kthNode=findKthNode(head,len-k);
        head=kthNode->next;
        kthNode->next=nullptr;
        return head;
        
    }
};