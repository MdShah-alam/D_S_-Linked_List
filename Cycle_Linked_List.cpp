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

int find_mid_point(Node *&head)
{
    Node *slow=head;
    Node *fast=head;

    int count=1;

    if(head==NULL)
        return -1;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        count++;
    }
    return count;
}

void create_cycle(Node *&head,int cont)
{
    int count=1;
    Node *temp=head;
    Node *startnode;

    if(head==NULL)
        return ;

    while(temp->next!=NULL)
    {
        if(count==cont)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool check_cycle(Node *&head)
{
    Node *slow=head;
    Node *fast=head;

    if(head==NULL)
        return false;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
            return true;
    }
    return false;
}

void remove_cycle(Node *&head)
{
    Node *slow=head;
    Node *fast=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);

        fast=head;

    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }

    slow->next=NULL;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter Node number :";
    cin>>n;

    cout<<"Enter Node elements :";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int mid=find_mid_point(head);

    cout<<"mid point is :"<<mid<<endl<<endl;

    int cont;
    cout<<"Enter Cycle position :";
    cin>>cont;

    create_cycle(head,cont);

    //display(head);

    bool found=check_cycle(head);

    if(found)
        cout<<endl<<"cycle is exist ."<<endl<<endl;
    else
        cout<<endl<<"cycle is not exist ."<<endl<<endl;

    remove_cycle(head);

    display(head);

    return 0;
}
