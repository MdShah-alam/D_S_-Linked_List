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

void insert_at_tail(Node *&head ,int val)
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

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<< "  ";
        n=n->Next;
    }
    cout<<endl;
}

Test search_by_duplicate_value_array(Node *&head ,int key)
{
    Node *temp=head;
    Test T;
    int k=1;
    int count=1;

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

int main()
{
    int n;
    Node *head=NULL;
    cout<<"Enter the numbers of Node : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }
    display(head);

    cout<<"Enter the searching value : ";
    int b;
    cin>>b;

    Test T;

    T=search_by_duplicate_value_array(head,b);
    if(T.position[0]==1)
        cout<<"This value is not exist in the list."<<endl;
    else
    {
        int size=T.position[0];
        cout<<"The value is found at position : ";
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
