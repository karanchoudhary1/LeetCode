//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    vector<int> v;
    Node *compute(Node *head)
    {
        // your code goes here
        Node* strt=head;
        stack<pair<int,int>> st;
        int cnt=0;
        while(head!=NULL){
            if(st.empty()){
                st.push({head->data,cnt});
                cnt++;
                head=head->next;
                continue;
            }
            while(st.size()!=0 && st.top().first<head->data){
                v.push_back(st.top().second);
                st.pop();
            }
            st.push({head->data,cnt});
            head=head->next;
            cnt++;
        }
        head=strt;
        Node* ans=NULL;
        int a=0;
        int i=0;
        sort(v.begin(),v.end());
        //for(auto x:v) cout<<x<<endl;
        while(i<v.size()){
            if(a==v[i]){
                a++;
                head=head->next;
                i++;
                continue;
            }
                if(ans==NULL) {
                    ans=head;
                    strt=ans;
                    head=head->next;
                }
                else{
                    strt->next=head;
                    strt=head;
                    head=head->next;
                }
                a++;
            }
            if(ans==NULL) return head;
        strt->next=head;
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends