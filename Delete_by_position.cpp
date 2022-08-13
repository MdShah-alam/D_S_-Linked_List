#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insert_at_tail(Node *&head,int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head =newNode;
        return ;
    }
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void insert_position(Node *&head,int val)
{
    Node *temp=head;
    Node *newNode=new Node(val);
    if(head->data>val)
    {

        head=newNode;
        head->next=temp;
    }
    else
    {
        while(temp!=NULL)
            if(temp->next->data<val)
                temp=temp->next;
            else
            {
                Node *save=temp->next;
                temp->next=newNode;
                temp->next->next=save;
                return ;
            }
            if(temp==NULL)
                temp->next=newNode;
    }
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<"  ";
        n=n->next;
    }
    cout<<endl;
}
int main()
{
    struct Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }
    display(head);
    cout<<"position :";
    int pos;
    cin>>pos;
    insert_position(head,pos);
    display(head);
}
