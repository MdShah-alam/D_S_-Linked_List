#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char val;
    Node *next;

    Node(char val)
    {
        this->val=val;
        next=NULL;
    }
};

void insert_at_tail(Node *&head,char val)
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

Node *reverse_list(Node *&head)
{
    Node *curr=head;
    Node *prev=NULL;

    while(curr!=NULL)
    {
        Node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

int isPalindrome(Node *&head)
{
    Node *temp=head;

    head=reverse_list(head);

    Node *temp1=head;

    while(temp!=NULL)
    {
        if(temp->val!=temp1->val)
            return -1;
        temp=temp->next;
        temp1=temp1->next;
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;

    for(int i=0;i<n;i++)
    {
        char a;
        cin>>a;
        insert_at_tail(head,a);
    }

    cout<<isPalindrome(head)<<endl;

    return 0;
}
