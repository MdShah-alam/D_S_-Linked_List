#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

void insert_at_tail(Node *&head,int val)
{
    Node *newNode =new Node(val);

    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
}

void display(Node *&head)
{
    Node *n=head;

    while(n->next!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->next;
    }
    cout<<n->val<<endl<<endl;

    while(n!=head)
    {
        cout<<n->val<<"  ";
        n=n->prev;
    }
    cout<<n->val<<endl<<endl;
}

void display1(Node *&head,int n)
{
    Node *temp=head;

    while(n!=1)
    {
        temp=temp->next;
        n--;
    }

    while(temp!=head)
    {
        cout<<temp->val<<"  ";
        temp=temp->prev;
    }
    cout<<temp->val<<endl<<endl;
}

int main()
{
    Node *head=NULL;

    int n,a;
    cout<<"Enter Node number :";
    cin>>n>>a;

    cout<<"Enter Node value :";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int ar[a];

    for(int i=0;i<a;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<a;i++)
    {
        display1(head,ar[i]);
    }

    return 0;
}
