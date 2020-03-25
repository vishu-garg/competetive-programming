#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int item;
    Node *next;
    // constructors
    Node();
    Node(int item , Node *add_on=NULL);
};

Node::Node()
{
    next=NULL;
}


Node::Node(int itm , Node *add_on)
{
    item=itm;
    next=add_on;    
}

class Stack
{
// private:
    /* data */
public:
    Stack();
    bool empty() ;
    string push(const int &item);
    string pop();
    string top(int &item) ;
    void show_stack();
    // ~Stack();
protected:
    Node *top_node;
};

Stack::Stack(/* args */)
{ 
    top_node=NULL;
}

string Stack::push(const int &item)
{
    Node *new_top=new Node(item,top_node);
    if(new_top==NULL) return "overflow";
    top_node=new_top;
    return "success";
}

string Stack::pop()
{
    Node *old_top=top_node;
    if(top_node==NULL)return "underflow";
    top_node=old_top->next;
    delete old_top;
    return "success";
}

bool Stack::empty()
{
    if(top_node==NULL)
    return true;
    return false;
}

string Stack :: top(int &itm)
{
    if(top_node==NULL)
    return "underflow";
    itm=top_node->item;
    return "success";
}

void Stack::show_stack()
{
    Node *ptr=top_node;
    if(ptr==NULL)
    {cout<<"Stack is Empty"<<endl;return;}
    cout<<ptr->item<<" <---"<<endl;
    ptr=ptr->next;
    while(ptr!=NULL)
    {
        cout<<ptr->item<<endl;
        ptr=ptr->next;
    }
    return;
}

int main()
{
    Stack obj;
    obj.push(1);
    obj.push(3);
    obj.push(2);
    obj.pop();obj.pop();obj.pop();
    obj.show_stack();
}
