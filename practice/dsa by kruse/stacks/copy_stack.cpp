const int maxstack = 10;

class Stack{
    public:
    Stack();
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
    // Error_code copy_stack(Stack &dest , Stack &source);
    // friend  Error_code copy_stack(Stack &dest , Stack &source);
    private:
    int count;
    Stack_entry entry[maxstack];
};

Error_code Stack::push(const Stack_entry &item)
{
    Error_code outcome=success;
    if(count>=maxstack)
    outcome=overflow;
    else 
    entry[count++]=item;
    return outcome;
}

Error_code Stack::pop()
{
    Error_code outcome=success;
    if(count==0)
    outcome=underflow;
    else 
    --count;
    return outcome;
}

Error_code Stack::top(Stack_entry &item) const
{
    Error_code outcome=success;
    if(count==0)
    outcome=underflow;
    else 
    item=entry[count-1];
    return outcome;
}

bool Stack::empty() const{
    bool outcome=true;
    if(count>0) outcome=false;
    return outcome;
}

// Error_code  Stack::copy_stack(Stack &dest , Stack &source)
// {
//     dest=source;
//     return success;
// }

// {
//     Error_code detected=success;
//     Stack temp;
//     Stack_entry item;
//     while(detected==success && !source.empty()){
//         detected=source.top(item);
//         detected=source.pop();
//         if(detected==success)detected=temp.push(item);
//     }

//     while(detected==success && !temp.empty()){
//         detected=temp.top(item);
//         detected=temp.pop();
//         if(detected==success)detected=dest.push(item);
//     }
// return detected;
// }

// {
//     dest.count=source.count;
//     for(int i=0;i<source.count;i++)
//     dest.entry[i]=source.entry[i];
//     return success;
// }


Stack::Stack()
{
    count=0;
}