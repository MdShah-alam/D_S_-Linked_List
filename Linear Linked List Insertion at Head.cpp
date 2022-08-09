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
        temp=temp->Next;

    temp->Next=newNode;
}

void insertAtHead(Node *&head,int val)
{
    //s1 : creation a Node.
    Node *newNode=new Node(val);

    //s2 : Update of newNode->Next.
    newNode->Next=head;

    //s3 : Update head.
    head=newNode;
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

    cout<<"Choice 1 : insertion at tail"<<endl<<"Choice 2 : insertion at head"<<endl<<"Choice 3 : Exit"<<endl<<endl;

    cout<<"Enter 1st Node : ";
    int choice=2;
    while(choice==1 || choice==2)
    {
        int val;
        cin>>val;
        if(choice==2)
            insertAtTail(head,val);

        else if(choice==1)
            insertAtHead(head,val);

        cout<<"Enter your choice : ";
        cin>>choice;

    }

    cout<<endl;
    display(head);

    return 0;
}
