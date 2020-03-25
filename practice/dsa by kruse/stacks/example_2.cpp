int max_stack = 10;

class Extended_stack {
    public:
    Extended_stack();
    Error_code pop();
    Error_code push(const Stack_entry &item)
    Error_code top(stack_entry & item) const;
    bool empty() const;

    void clear();
    bool full() const;
    int size() const;

    private: 
    int count;
    Stack_entry entry[maxstack];
};

void Extended_stack::clear()
{
    count=0;
}

bool Extended_stack::full()
{
    bool res=false;
    if(count>=max_stack)
    res=true;
    return res;
}

int Extended_stack::size()
{
    return count;
}
