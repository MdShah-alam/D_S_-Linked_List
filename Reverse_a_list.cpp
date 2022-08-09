#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *Next;

    Node(int val)
    {
        this->val=val;
        Next=NULL;
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

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }

    temp->Next=newNode;
}

void reverseList(Node *&head,int a,int b)
{
    Node *curr=head;
    Node *prev=NULL;

    int i=1;
    while(i!=a)
    {
        curr=curr->Next;
        prev=prev->Next;
        i++;
    }

    while(i!=b)
    {
        Node *temp=curr->Next;
        curr->Next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of Node : ";
    cin>>n;
    Node *head=NULL;
    cout<<"Enter the elements of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int a,b;
    cin>>a>>b;

    reverseList(head,a,b);

    display(head);
}
