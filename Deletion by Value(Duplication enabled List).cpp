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
    Node *newNode =new Node(val);

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

void delete_duplicate_value(Node *&head,int val)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->Next->val==val)
        {
            Node *delNode=temp->Next->Next;
            delete temp->Next;
            temp->Next=delNode;
        }
        temp=temp->Next;
    }
}

void delete_value(Node *&head,int val)
{
    Node *temp=head;

    while(temp->Next->val!=val)
    {
        temp=temp->Next;
    }
    Node *save=temp->Next->Next;

    delete temp->Next;

    temp->Next=save;
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
    Node *head=NULL;

    cout<<"Enter the number of Node : ";
    int n;
    cin>>n;

    cout<<"Enter the value of Node : ";

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    cout<<"Enter duplicate value : ";
    int a;
    cin>>a;

    delete_duplicate_value(head,a);
//    delete_value(head,a);
    display(head);
}
