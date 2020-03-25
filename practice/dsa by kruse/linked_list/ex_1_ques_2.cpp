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

int main()
{
    // Node *p0 =new Node(0);
    // Node *p1 = new Node(1);
    // p0->next=p1;
    // Node *p2 = new Node(2);
    // p1->next=p2;
    // p2->next=p1;

    // Node *p0 = new Node(0);
    // p0->next=Node *p1 = new Node(1);

    // Node *p0= new Node(0);
    // Node *p1= new Node(1,p0);
    // Node *p2= p1;
    // cout<<p0->item<<" "<<p0;
    // cout<<endl<<p1->next<<endl;

    // Node *p0=new Node(0);
    // Node *p1=new Node(1);
    // p0->next=p1;
    // Node *p2=new Node(2,p1);
    // p1->next=p2;
    // cout<<p1<<" "<<p2->next<<endl;
}