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

int findmid(node *head)
{
    node *slow=head;
    node *fast=head;

    cout<<head->val<<endl;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

//    if(fast->next==NULL)
//        slow=slow->next;

    return slow->val;
}

void remove_duplicate_node(node *&head)
{
    node *dummy=NULL;

    node *prev=dummy;

    while(head!=NULL)
    {
        if(head->next!=NULL  && head->val==head->next->val)
        {
            while(head->next!=NULL && head->val==head->next->val)
                head=head->next;
            prev->next=head->next;
        }
        else
            head=head->next;
    }
    head=dummy->next;
}

void remove_value(node *&head,int key)
{
    node *temp=head;

    while(temp->next!=NULL)
    {
        if(temp->next->val==key)
        {
            node *save=temp->next->next;
            delete temp->next;
            temp->next=save;
        }
        else
        {
            temp=temp->next;
        }
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
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }
    display(head);

    //    int k;
    //    cin>>k;
    //
    //    remove_value(head,k);
    //
    //    display(head);

    remove_duplicate_node(head);

    display(head);

    cout<<findmid(head)<<endl;

    return 0;
}
