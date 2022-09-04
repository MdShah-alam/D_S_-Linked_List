#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val=val;
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

Node *remove_zero_sum_list(Node *&head)
{
    if(head==NULL)
        return 0;

    unordered_map<int,Node*>m;

    Node *dummy=new Node(0);
    dummy->next=head;
    m[0]=dummy;
    int prefixsum=0;

    while(head!=NULL)
    {
        prefixsum+=head->val;

        if(m.find(prefixsum)!=m.end())
        {
            Node *start=m[prefixsum];
            int sum=prefixsum;

            while(start!=NULL && start!=head)
            {
                start=start->next;
                sum+=start->val;

                if(start!=head)
                    m.erase(sum);
            }
            m[prefixsum]->next=head->next;
        }
        else
            m[prefixsum]=head;

        head=head->next;
    }
    return dummy->next;
}

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val<<"   ";
        n=n->next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert_at_tail(head,a);
    }

    display(head);

    head=remove_zero_sum_list(head);

    display(head);

    return 0;
}
