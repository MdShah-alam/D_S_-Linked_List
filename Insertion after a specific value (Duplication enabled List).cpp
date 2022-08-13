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

void insert_after_duplicate_value(Node *&head,int val,int key)
{
    Node *newNode=new Node(val);

    Node *temp=head;

    while(temp!=NULL)
    {
        if(temp->val==key)
        {
            Node *save=temp->Next;

            temp->Next=newNode;

            temp->Next->Next=save;
        }
        temp=temp->Next;
    }


//    while(temp!=NULL)
//    {
//        if(temp->val!=key)
//
//            temp=temp->Next;
//
//        else
//        {
//            Node *save=temp->Next;
//
//            temp->Next=newNode;
//
//            temp->Next->Next=save;
//
//            temp=temp->Next->Next;
//        }
//    }
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
    int n;
    cout<<"Enter the numbers of Node : ";
    cin>>n;

    cout<<"Enter elements of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    cout<<"Enter the inserting value :";
    int val;
    cin>>val;
    cout<<"Enter the value after inserting:";
    int k;
    cin>>k;
    insert_after_duplicate_value(head,val,k);

    display(head);

    return 0;
}
