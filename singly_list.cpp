#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
Node *insert_at_tail(int val , Node *&head)
{
    if(head==NULL)
        return head = new Node(val);
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    Node *newNode=new Node(val);
    temp->next=newNode;
    return head;
}
void print(Node* head)
{
    cout<<endl;
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insert_at_position(Node *&head, int i, int val)
{
    Node *newNode = new Node(val);
    if(i==1){
        newNode->next=head;
        head=newNode;
        return ;
    }
    Node *temp=head;

    while(i!=2 && temp!=NULL){
        temp=temp->next;
        i--;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void reverse_list(Node *&head)
{
    if(head==NULL || head->next==NULL)
        return ;
    Node *temp=NULL;
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev=curr;
        curr=temp;
    }
    head = prev;
}
void deletion(Node *&head , int val)
{
    if(head->val==val){
        Node *newNode = head->next;
        delete(head);
        head=newNode;
        return ;
    }
    Node *temp=head;
    Node *tp=NULL;
    while(temp->val!=val){
        tp=temp;
        temp=temp->next;
    }
    tp->next=temp->next;
    delete(temp);
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(a,head);
    }
    print(head);
    cout<<"Insert position : ";
    int i;
    cin>>i;
    cout<<"Insert value : ";
    int x;
    cin>>x;
    insert_at_position(head , i, x);
    print(head);
    reverse_list(head);
    print(head);
    int y;
    cout<<"Enter value that you wanna delete : ";
    cin>>y;
    deletion(head,y);
    print(head);
}
