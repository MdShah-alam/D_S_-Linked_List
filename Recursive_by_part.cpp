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
        next=NULL;
    }
};

void insert_at_tail(Node *&head,int val)
{
    Node *newNode=new Node(val);

    if(head==NULL)
    {
        head=newNode;
        return ;
    }

    Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}

Node * reverse_recursive(Node *&head,int k)
{
    Node *currptr=head;
    Node *prevptr=NULL;
    Node *nextptr;

    int count=0;

    while(currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(nextptr!=NULL)
        head->next=reverse_recursive(nextptr, k);

     return prevptr;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;

    int n;
    cout<<"Enter Node number :";
    cin>>n;

    cout<<"Enter Node element :";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int k;
    cin>>k;

    head=reverse_recursive(head,k);

    display(head);

    return 0;
}
