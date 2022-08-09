#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* Next;

    Node(int val)
    {
        this->val=val;
        Next=NULL;
    }
};

void insert_at_tail(Node *&head,int val)
{
    Node* newNode=new Node(val);

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

void insert_at_any_position(Node *&head,int pos,int val)
{
    Node *newNode=new Node(val);

    Node *temp=head;

    for(int i=1; i<pos-1; i++)
    {
        temp=temp->Next;
    }

    Node *save=temp->Next;
    temp->Next=newNode;
    newNode->Next=save;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<" " ;
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head = NULL;
    cout<<"How many Node do you want to create :";
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        insert_at_tail(head,val);
    }

    display(head);

    cout<<"which position do you want to insert :";
    int pos;
    cin>>pos;
    cout<<"which value do you want to insert :";
    int v;
    cin>>v;
    insert_at_any_position(head,pos,v);

    display(head);

    cout<<endl;

    return 0;
}
