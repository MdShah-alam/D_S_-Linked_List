#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};

void insertAtTail(Node *&head,int val)
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

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL)
            cout<<"->";
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;

    int n;
    cout<<"Enter the numbers of Node : ";
    cin>>n;
    cout<<"Enter the value of Node : ";

    while(n!=0)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);
        n--;
    }

    display(head);

    return 0;
}
