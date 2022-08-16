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

void rotate_list(Node *&head,int k)
{
    Node *temp=head;
    int n=0;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        n++;
    }

    Node *curr=head;

    if(k>n)
        k=k%n;

    if(k==0)
        return ;

    for(int i=1;i<k;i++)
    {
        curr=curr->next;
    }

        temp->next=head;

        head=curr->next;

        curr->next=NULL;

    return ;
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

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    int k;
    cout<<"How many times rotate :";
    cin>>k;

    rotate_list(head,k);

    display(head);

    return 0;
}
