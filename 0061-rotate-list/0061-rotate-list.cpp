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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int cnt=0;
        ListNode* t=head;
        ListNode* c=head;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        int d=cnt;
        k=k%cnt;
        cnt-=k;
        k=cnt;
        
        if(k==d) return t;
        k--;
        head=t;
        ListNode* ans;
        while(k--){
            head=head->next;
        }
        ans=head->next;
        head->next=NULL;
        t=ans;
        while(t->next!=NULL) t=t->next;
            t->next=c;
        return ans;
    }
};