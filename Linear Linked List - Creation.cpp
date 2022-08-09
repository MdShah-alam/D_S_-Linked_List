#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int val)
    {
        value=val;
        next=NULL;
    }
};

void insertAtTail(Node *&head , int val)
{
    Node *newNode=new Node(val);

    if(head==NULL)
    {
        head=newNode;
        return ;
    }
    Node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;

}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
            cout<<" -> ";
        n=n->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=NULL;

    int n;
    cout<<"How many value do you want to insert : ";
    cin>>n;

    cout<<"Enter your val : ";

    while(n!=0)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);

        n--;
    }

//    insertAtTail(head,3);
//    insertAtTail(head,6);
//    insertAtTail(head,8);
//    insertAtTail(head,2);
//    insertAtTail(head,10);


//    Node *second=new Node();
//    Node *third=new Node();
//    Node *fourth=new Node();
//    Node *fiveth=new Node();
//    Node *sixth=new Node();

//    head->value=3;
//    second->value=5;
//    third->value=1;
//    fourth->value=10;
//    fiveth->value=8;
//    sixth->value=100;

//    head->next=second;
//    second->next=third;
//    third->next=fourth;
//    fourth->next=fiveth;
//    fiveth->next=sixth;
//    sixth->next=NULL;

    display(head);

    return 0;
}
