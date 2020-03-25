#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int item;
    Node *next;
    Node();
    Node(int item, Node *ptr = NULL);
};

Node::Node()
{
    next=NULL;
}

Node::Node(int item2 , Node *ptr2)
{
    item=item2;
    next=ptr2;
}


class Queue
{
protected:
    Node *front , *rear;
    int size;
public:
    Queue();
    void push(const int &itm);
    void pop();
    bool empty();
    void to_be_served(int &itm);
    void show_queue();
};

Queue::Queue()
{
    size=0;
    front=rear=NULL;
}

void Queue::push(const int &itm)
{
    Node *ptr=new Node(itm);
    if(front==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else 
    {
        rear->next=ptr;
        rear=ptr;
    }
    size++;
    return;
}

void Queue::pop()
{
    if(front==NULL)
    {cout<<"UNDERFLOW";return;}
    size--;
    Node *ptr=front;
    front=front->next;
    cout<<endl<<"Successfully Deleted- "<<ptr->item<<" from queue"<<endl;
    delete ptr;
    return;
}

void Queue::show_queue()
{
    if(size==0)
    {cout<<"Queue is empty "<<endl;return;}
    else 
    {
        cout<<endl<<"Number of Elements in Queue = "<<size<<endl;
        Node *ptr=front;
        while(ptr!=NULL)
        {
            cout<<ptr->item<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    return;
}

void Queue::to_be_served(int &frnt)
{
    if(front==NULL)
    {cout<<endl<<"UNDERFLOW"<<endl;return;}
    frnt=front->item;
    return;
}

bool Queue::empty()
{
    if(size==0)
    return true;
    return false;
}

int main()
{
    // cout<<"1";
    Queue obj;
    // push 1,2,3 in queue()
    obj.push(1);obj.push(2);obj.push(3);
    //show my queue
    obj.show_queue();
    //pop elements from queue
    obj.pop();
    obj.show_queue();
    obj.push(2);
    obj.push(7);
    obj.show_queue();
    obj.pop();obj.pop();obj.pop();obj.pop();
    //get front element
    int front;
    obj.to_be_served(front);
    if(!obj.empty())
    cout<<endl<<"FRONT IS - "<<front<<endl;
    //is queue empty
    cout<<endl<<obj.empty();

}

