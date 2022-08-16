#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

void insert_at_tail(node *&head,int val)
{
    node *newnode=new node(val);

    if(head==NULL)
    {
        head=newnode;
        return ;
    }
    node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void remove_duplicate_node(node *&head)
{
    if(head==NULL || head->next==NULL)
    {
        return ;
    }

    node *temp=head;

    while(temp->next!=NULL)
    {
        if(temp->val==temp->next->val)
        {
            node *del=temp->next;
            temp->next=del->next;
            delete del;
        }
        else
            temp=temp->next;
    }
}

void display(node *n)
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
    node *head=NULL;

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

    remove_duplicate_node(head);

    display(head);

    return 0;
}
