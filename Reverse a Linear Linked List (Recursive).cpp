#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

void insert_at_tail(Node *&head,int val)
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head=newNode;
        return ;
    }
    Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
Node *reverse_by_recursive(Node *&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node *newNode=reverse_by_recursive(head->next);

    head->next->next=head;
    head->next=NULL;
    return newNode;
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    cout<<"Enter the number of Node : ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }
    display(head);
    head=reverse_by_recursive(head);
    display(head);
}
