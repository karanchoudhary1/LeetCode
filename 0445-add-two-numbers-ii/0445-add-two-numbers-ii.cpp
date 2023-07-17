class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        ListNode *h1=l1;
        ListNode *a1=h1;
        ListNode *h2=l2;
        ListNode *a2=h2;
        int c=0;
        bool flag=true;
        stack<int>s;
        stack<int> s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
}
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
}
        if(s1.size()>s2.size()) flag=true;
        else flag=false;
        while(s1.size()!=0 && s2.size()!=0){
            int x=s1.top()+s2.top()+c;
            if(x>=10) c=1;
            else c=0;
            s.push(x%10);
            s1.pop();
            s2.pop();
        }
        while(s1.size()!=0){
            int x=s1.top()+c;
            if(x==10) c=1;
            else c=0;
            s.push(x%10);
            s1.pop();
        }
            while(s2.size()!=0){
            int x=s2.top()+c;
            if(x==10) c=1;
            else c=0;
            s.push(x%10);
            s2.pop();
        }
        if(c==1) s.push(1);
        if(flag==true){
            while(h1->next!=NULL){
            h1->val=s.top();
            s.pop();
            h1=h1->next;
            }
            h1->val=s.top();
            s.pop();
            if(s.size()!=0) {
            ListNode *w=new ListNode(s.top());
            h1->next=w;
                w->next=NULL;
}
            return a1;
}
        else {
            while(h2->next!=NULL){
            h2->val=s.top();
            s.pop();
            h2=h2->next;
            }
            h2->val=s.top();
            s.pop();
            if(s.size()!=0) {
            ListNode *w=new ListNode(s.top());
            h2->next=w;
            w->next=NULL;
}
            return a2;
} 
        }
};