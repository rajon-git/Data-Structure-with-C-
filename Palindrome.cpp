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
void insert_at_tail(Node *&head, Node *&tail,int val)
{
    Node *newnode=new Node(val);
    if(tail == NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->pre=tail;
    tail=tail->next;
}
bool palindrome_node(Node *head, Node *tail)
{
    Node *i=head;
    Node *j=tail;
    while(i != j && i->next != j)
    {
        if(i->val!=j->val)
        {
            return false;
        }
        i = i->next;
        j = j->pre;
    }
    if(i->val != j->val)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}
int main()
{
    Node *head=NULL;
    Node *tail= NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head,tail,val);
    }
    if(palindrome_node(head,tail))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}