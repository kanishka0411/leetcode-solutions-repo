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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *before=dummy;
        while(true){
            ListNode *check=before;
            for(int i=0;i<2 && check!=nullptr;i++){
                check=check->next;
            }
            if(!check) break;
            int cnt=2;
            ListNode* first=before->next;
            ListNode *prev=nullptr;
            ListNode *temp=first;
            while(cnt--){
                ListNode *front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            before->next=prev;
            first->next=temp;
            before=first;

        
            
        }
        return dummy->next;
        
    }
};