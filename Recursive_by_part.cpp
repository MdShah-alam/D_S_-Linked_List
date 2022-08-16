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
    Node *newNode=new Node(val);

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

Node *reverse_recursive(Node *&head,int count)
{
    if(head==NULL || head->next==NULL)
        return head;

    if(count!=0)
    {
        cout<<count<<endl;
        count--;
        Node *newNode=reverse_recursive(head->next,count);

        head->next->next=head;

        head->next=NULL;

        return newNode;
    }
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

    int n;
    cout<<"Enter Node number :";
    cin>>n;

    cout<<"Enter Node element :";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int k;
    cin>>k;

    head=reverse_recursive(head,k);

    display(head);

    return 0;
}
