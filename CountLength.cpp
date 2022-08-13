#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
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

int countLength(Node *&head)
{
    Node *temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the number of Node : ";
    cin>>n;

    Node *head=NULL;

    cout<<endl;
    cout<<"Enter element of Node : ";
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head, a);
    }

    int size=countLength(head);

    cout<<size<<endl;
}
