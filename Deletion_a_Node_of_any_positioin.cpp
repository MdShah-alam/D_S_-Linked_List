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

void insert_at_tail(Node *&head, int val)
{
    Node *newNode=new Node(val);

    if(head==NULL)
    {
        head = newNode;
        return ;
    }

    Node *temp=head;

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }

    temp->Next=newNode;
}

void delete_head(Node *&head)
{
    Node *temp=head;

    if(temp!=NULL)
    {
        head=temp->Next;

        delete temp;
    }
    else
    {
        cout<<"Your Linked list is empty .";
    }

}

void delete_at_tail(Node *&head)
{
    Node *temp=head;

    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode=temp->Next;

        temp->Next=NULL;

        delete delNode;
    }

    else
    {
        if(temp==NULL)
            cout<<"List is NULL . "<<endl;
        else
            delete_head(head);
    }
}

void delete_at_any_position(Node *&head,int pos)
{

}

void display(Node *n)
{
    if(n!=NULL)
    {
        while(n!=NULL)
        {
            cout<<n->val<< "  ";
            n=n->Next;
        }
    }
    else
        cout<<"List is NULL . ";

            cout<<endl;
}

int main()
{
    Node *head=NULL;

    cout<<"Enter the number of Node : ";
    int n;
    cin>>n;

    cout<<"Enter the elements of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

//    delete_head(head);
//
//    delete_at_tail(head);

     cout<<

      delete_at_any_position(head);

    display(head);
}
