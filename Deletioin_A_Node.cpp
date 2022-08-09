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

void delete_the_val(Node *head,int pos)
{
    Node *temp=head;

    for(int i=0;i<pos-2;i++)
    {
        temp=temp->Next;
    }

    Node *c=temp->Next->Next;

    delete temp->Next;

    temp->Next=c;

}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<" ";
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;

    cout<<"Enter numbers of node : ";

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    cout<<"Enter which position do you want to delete : ";

    int b;
    cin>>b;

    delete_the_val(head, b);

    display(head);

}
