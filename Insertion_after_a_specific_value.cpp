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

void insert_after_value(Node *&head,int val,int after_val)
{
    Node *temp=head;

    Node *newNode=new Node(val);

    while(temp->val!=after_val)
    {
        temp=temp->Next;
    }
    Node *save=temp->Next;
    temp->Next=newNode;
    temp->Next->Next=save;
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
    cout<<"Enter the numbers of Node :";
    cin>>n;
    Node *head=NULL;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int a;
    cout<<"Enter the value that you want to insert :";
    cin>>a;

    int b;
    cout<<"Enter the value that after you insert : ";
    cin>>b;

    insert_after_value(head,a,b);
     display(head);
}
