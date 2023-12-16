#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *pre;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->pre=NULL;
    }
};
int size(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void insert_at_head(Node *&head,Node*&tail,int val)
{
    Node *newnode=new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next=head;
    head->pre = newnode;
    head=newnode;
}
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->pre= tail;
    tail = tail->next;
}

void insert_at_position(Node *head, int pos, int val)
{
    Node *newnode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;     
    tmp->next = newnode;           
    newnode->next->pre = newnode; 
    newnode->pre = tmp;           
}
void print_list_normal(Node *head)
{
    Node *tmp=head;
    cout << "L -> ";
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}
void print_list_reverse(Node *tail)
{
    Node *tmp=tail;
    cout << "R -> ";
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->pre;
    }
}
int main()
{
    int test;
    cin>>test;
    Node *head=NULL;
    Node *tail=NULL;
    for (int i=0;i<test;i++)
    {
    int pos, val;
    cin>>pos>>val;

    if (pos > size(head))
    {
        cout << "Invalid"<<endl;
    }
    else if (pos == 0)
    {
        insert_at_head(head, tail, val);
        print_list_normal(head);
        cout<<endl;
        print_list_reverse(tail);
        cout<<endl;
    }
    else if (pos == size(head))
    {
        insert_tail(head, tail, val);
        print_list_normal(head);
        cout<<endl;
        print_list_reverse(tail);
        cout<<endl;
    }
    else
    {
        insert_at_position(head, pos, val);
        print_list_normal(head);
        cout<<endl;
        print_list_reverse(tail);
        cout<<endl;
    }
    
    }
    return 0;
}