#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int val;
    doublyNode *next;
    doublyNode *prev;

    doublyNode(int val)
    {
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

void insert_at_tail(doublyNode *&head,int val)
{
    doublyNode *newNode=new doublyNode(val);

    if(head==NULL)
    {
        head=newNode;
        return ;
    }

    doublyNode *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;

    newNode->prev=temp;
}

void insert_at_position(doublyNode *&head,int pos,int val)
{
    doublyNode *newNode=new doublyNode(val);

    doublyNode *temp=head;

    for(int i=1; i<pos-1; i++)
        temp=temp->next;

    doublyNode *save1=temp->next;

    temp->next=newNode;

    save1->prev=newNode;

    newNode->prev=temp;

    newNode->next=save1;

}

void insert_at_head(doublyNode *&head,int val)
{
    doublyNode *newNode=new doublyNode(val);

    head->prev=newNode;

    newNode->next=head;

    head=newNode;
}

void display(doublyNode *&head)
{
    doublyNode *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->val<<"  ";
        temp=temp->next;
    }
    cout<<endl<<endl;
}

void reverse_display(doublyNode *&head)
{
    doublyNode *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    cout<<"After Reverse :";

    while(temp!=NULL)
    {
        cout<<temp->val<<"  ";
        temp=temp->prev;
    }
    cout<<endl<<endl;
}

int main()
{
    doublyNode *head=NULL;

    int choice=1;
    cout<<"1.insert at tail"<<endl;
    cout<<"2.insert at head"<<endl;
    cout<<"3.exit"<<endl;

    /** int n;
        cout<<"Enter the number of Node :";
        cin>>n;
        cout<<"Enter the element of Node :";

        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            insert_at_tail(head,a);
        }*/

    while(choice==1 || choice==2)
    {
        if(choice==1)
        {
            int val;
            cout<<"Enter value :";
            cin>>val;
            insert_at_tail(head,val);
        }
        else
        {
            int val;
            cout<<"Enter value :";
            cin>>val;
            insert_at_head(head,val);
        }
        cout<<"Enter your choice : ";
        cin>>choice;
    }
    cout<<endl;
    cout<<"Before insert and Reverse :";
    display(head);


    cout<<"Enter position : ";
    int k;
    cin>>k;

    cout<<"value : ";
    int vl;
    cin>>vl;

    insert_at_position(head,k,vl);

    cout<<endl;
    cout<<"After insert : ";
    display(head);

    reverse_display(head);
}
