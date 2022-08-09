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

void insert_at_tail(Node *&head , int val)
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

int countLength(Node *n)
{
    int cont=0;
    while(n!=NULL)
    {
        cont++;
        n=n->Next;
    }
    return cont;

}

int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head , a);
    }

    int size =countLength(head);

    cout<<size;
}
