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
    doublyNode *newNode = new doublyNode(val);

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

int search_position(doublyNode *&head,int key)
{
    doublyNode *temp=head;

    if(temp==NULL)
        return -1;

    int j=1;

    while(temp!=NULL)
    {
        if(temp->val==key)
        {
            return j;
        }
        temp=temp->next;
        j++;
    }
    return -1;
}

void display(doublyNode *n)
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
    doublyNode *head=NULL;

    int n;
    cout<<"Enter the size of Node :";
    cin>>n;

    cout<<"Enter the elements of Node :";
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    cout<<"Enter the searching value :";
    int value;
    cin>>value;

    int k=search_position(head,value);

    cout<<k<<endl;

    return 0;
}
