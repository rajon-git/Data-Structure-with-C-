#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    string val;
    Node *next;
    Node *pre;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string val)
{
    Node *newnode=new Node(val);
    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->pre= tail;
    tail=newnode;
}

void visit_address(Node *&head, string val)
{
    Node *tmp=head;
    bool found=false;
    while (tmp != NULL)
    {
        if(tmp->val== val)
        {
            cout << tmp->val << endl;
            found=true;
            head=tmp;
            break;
        }
        tmp=tmp->next;
    }
    if(!found)
        cout<<"Not Available"<<endl;
}

void next_node(Node *&head)
{
    if(head == NULL) cout<<"Not Available"<<endl;
    if(head != NULL && head->next != NULL)
    {
        head=head->next;
        cout<<head->val<<endl;
    }
    else
    {
        cout<<"Not Available"<<endl;
    }
}

void pre_node(Node *&head)
{
    if(head == NULL) cout<<"Not Available"<<endl;
    if(head!=NULL && head->pre!=NULL)
    {
        head=head->pre;
        cout<<head->val<<endl;
    }
    else
    {
        cout<<"Not Available"<<endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string val;
    while (true)
    {
        cin>>val;
        if(val == "end")
            break;
        insert_at_tail(head, tail, val);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string op,query;
        cin>>op;
        if(op == "visit")
        {
            cin>>query;
            visit_address(head,query);
        }
        else if(op == "next")
        {
            next_node(head);
        }
        else
        {
            pre_node(head);
        }
    }
    return 0;
}
