#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

void insert_at_tail(Node *&head,int a)
{
    Node *newNode=new Node(a);

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
    newNode->prev=temp;
}

void delete_tail(Node *&head)
{
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    Node *temp2=temp->prev;
    temp2->next=NULL;
    delete temp;

}

void delete_head(Node *&head)
{
    Node *temp=head;

    Node *temp2=temp->next;

    temp2->prev=NULL;

    delete temp;

    head=temp2;
}

void delete_any_position(Node *&head,int n)
{
    Node *temp=head;

    for(int i=1; i<n-1; i++)
    {
        temp=temp->next;
    }

    Node *save=temp->next->next;

    delete temp->next;

    temp->next=save;
    save->prev=temp;
}

void delete_by_value(Node *&head, int key)
{
    Node *temp=head;

    if(head->val==key)
    {
        Node *temp2=temp->next;

        temp2->prev=NULL;

        delete temp;

        head=temp2;

        return ;
    }

    while(temp->next->val!=key)
    {
        temp=temp->next;
    }

    Node *save=temp->next->next;

    delete temp->next;

    temp->next=save;
    save->prev=temp;
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
    cout<<"Enter Node number : ";
    cin>>n;

    cout<<"Enter value of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);
//    cout<<"After deleting tail: ";
//    delete_tail(head);
//    display(head);
//
//    cout<<"After deleting head: ";
//    delete_head(head);
//    display(head);
//
//    int k;
//    cout<<"Enter position to delete :";
//    cin>>k;
//
//    cout<<"After deleting any_position: ";
//    delete_any_position(head,k);

    cout<<"Enter value :";
    int val;
    cin>>val;
    delete_by_value(head,val);

    display(head);


    return 0;
}
