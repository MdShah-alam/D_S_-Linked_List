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

void insert_at_head(Node *&head,int val)
{
    Node *newNode=new Node(val);

    if(head==NULL)
    {
        newNode->next=newNode;
        head=newNode;
        return ;
    }
    Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;

    newNode->next=head;

    head=newNode;
}

void insert_at_tail(Node *&head,int val)
{
    Node *newNode=new Node(val);

    if(head==NULL)
    {
        insert_at_head(head,val);
        return ;
    }
    Node *temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
}

void display(Node *head)
{
    Node *n=head;
    do
    {
        cout<<n->val<<"  ";
        n=n->next;
    }
    while(n!=head);
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter Node number :";
    cin>>n;

    cout<<"Enter Node element :";
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

}
