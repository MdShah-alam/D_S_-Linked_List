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

struct Test
{
    int position[10000];
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

Test position_of_duplicate_value(Node *&head,int key)
{
    Node *temp=head;

    int count=1;
    int k=1;
    Test T;

    while(temp!=NULL)
    {
        if(temp->val==key)
        {
            T.position[k]=count;
            k++;
        }
        temp=temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"  ";
        n=n->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter the number of Node : ";
    cin>>n;

    cout<<"Enter the elements of Node : ";
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    int val;
    cout<<"Enter the searching value : ";
    cin>>val;

    Test T;

    T=position_of_duplicate_value(head,val);

    if(T.position[0]==1)
        cout<<"The List is empty ."<<endl;
    else
    {
        cout<<"The position of the value is :";
        int size=T.position[0];
        for(int i=1;i<size;i++)
        {
            cout<<T.position[i];
            if(i<size-1)
                cout<<" , ";
        }
        cout<<endl;
    }

    return 0;
}
