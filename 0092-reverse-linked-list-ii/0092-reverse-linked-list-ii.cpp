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
        ListNode* ans=head;
        //if(left==right) return ans;
        ListNode* prev=NULL;
       for(int i=1;i<left;i++){
          prev=head;
          head=head->next;
       }
       ListNode* y=prev;
       ListNode* x=head;
       prev=NULL;
       ListNode* curr;
       for(int i=left;i<=right;i++){
             curr=head->next;
             head->next=prev;
             prev=head;
             head=curr;
       }
       if(y==NULL){
           x->next=head;
           return prev;
       }
       y->next=prev;
       x->next=head;
       return ans;
    }
};