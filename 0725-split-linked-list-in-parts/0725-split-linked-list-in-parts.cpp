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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int dis=0;
        ListNode* x=head;
        while(head!=NULL){
            dis++;
            head=head->next;
        }
        head=x;
        int ctr=dis/k;
        int rem=dis%k;
        ListNode* prev=NULL;
        while(head!=NULL){
            v.push_back(head);
            for(int i=0;i<ctr && head!=NULL;i++) {
                prev=head;
                head=head->next;
            }
            if(rem!=0){
                rem--;
                prev=head;
                head=head->next;
            }
            prev->next=NULL;
        }
        while(v.size()!=k) v.push_back(NULL);
        return v;
    }
};