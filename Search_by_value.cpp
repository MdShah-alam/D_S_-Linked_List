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

void insert_at_tail(Node *&head,int val)
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

int Search_by_value(Node *head,int n)
{
    Node *temp=head;

    int cont=1;

    if(temp==NULL)
        return -1;

    while(temp->val!=n)
    {
        if(temp->Next==NULL)
            return -1;
        cont++;
        temp=temp->Next;
    }
    return cont;
}

void search_by_duplicate_value(Node *head,int key)
{
    Node *temp=head;

    int size=countLength(head);
    int position[size+1];

    cout<<size<<endl;

    int cont=1,k=1;

    bool found=true;

    while(temp!=NULL)
    {
        if(temp->val==key)
        {
            position[k]=cont;
            k++;
            found=false;
        }
        temp=temp->Next;
        cont++;
    }

    if(found)
        cout<<"this value is not exist in this list";
    else
    {
        position[0]=k;
        cout<<"the position of the value is : ";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1)
                cout<<",";
        }
    }
    cout<<endl;

}

void display(Node *head)
{
    Node *n=head;
    while(n!=NULL)
    {
        cout<<n->val<<" ";
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter size of Node : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }
    display(head);

    cout<<"Enter searching value : ";
    int b;
    cin>>b;

    search_by_duplicate_value(head,b);

//    Search_by_value(head,b);
//
//    int position=Search_by_value(head,val);
//
//    if(position==-1)
//        cout<<"this value is not exist in this list"<<endl;
//    else
//        cout<<"the position of the value is : "<<position<<endl;

    return 0;
}
