int maxstack = 10;

class Double_Stack()
{
    public:
    Double_Stack();
    Error_code push_a(const Stack_Entry &item);
    Error_code push_b(const Stack_Entry &item);
    Error_code pop_a();
    Error_code pop_b();
    private:
    int top_a;
    int top_b;
    Stack_Entry entry[maxstack];

};

Double_Stack::Double_Stack()
{
    top_a=0;
    top_b=maxstack-1;
}

Error_code Double_Stack::push_a(const Stack_Entry &item)
{
    Error_code outcome=success;
    if(top_a>=top_b)
    outcome=overflow;
    else 
    {
        entry[top_a]=item;
        top_a++;
    }
    return outcome;
} 

//similarly write for push_b;

Error_code Double_Stack::pop_a()
{
    if(top_a==0)
    return underflow;
    top_a--;
    return success;
}

//Similiarly for pop_b;