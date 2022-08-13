#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;

    Node(int data)
    {
        this->data=data;
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

void reverse_a_list(Node *&head)
{
    Node *curr=head;

    Node *prev=NULL;

    Node *next;

    if(head==NULL)
        return ;

    while(curr!=NULL)
    {
        next=curr->Next;

        curr->Next=prev;

        prev=curr;

        curr=next;
    }
    head=prev;

}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<"  ";
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

    cout<<endl;
    cout<<"Enter element of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head, a);
    }

    cout<<endl;
    cout<<"Before reversing : ";
    display(head);

    reverse_a_list(head);
    cout<<endl;

    cout<<"After reversing : ";
    display(head);

    return 0;
}
