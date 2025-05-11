#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

Node *insert_at_tail(int val , Node *&head)
{
    if(head==NULL)
        return head = new Node(val);
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    Node *newNode=new Node(val);
    temp->next=newNode;
    return head;
}
void print(Node* head)
{
    cout<<endl;
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void create_cycle(Node *head , int i)
{
    Node *temp=head;
    Node *tp=NULL;
    int k=1;
    while(temp->next!=NULL){
        temp=temp->next;
        k++;
        if(i==k)
            tp=temp;
    }
    temp->next=tp;
}

bool is_cycle(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(a,head);
    }
    print(head);
    cout<<"position of cycle : ";
    int i;
    cin>>i;
    create_cycle(head,i);
    if(is_cycle(head))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
