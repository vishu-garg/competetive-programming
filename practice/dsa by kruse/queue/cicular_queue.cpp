const int maxqueue=10;

class Queue{
    Queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;
    protected:
    int count;
    int front,rear;
    Queue_entry entry[maxqueue];
};

Queue::Queue()
{
    count=0;
    rear = maxqueue-1;
    front =0;
}

bool Queue::empty()const
{
    return count==0;
}

Error_code Queue::append(const Queue_entry &item)
{
    if(count>=maxqueue)return overflow;
    count++;
    rear=(rear+1)%maxqueue;
    entry[rear]=item;
    return success;
}

Error_code Queue::serve()
{
    if(coutn<=0) return underflow;
    count--;
    front=(front+1)%maxqueue;
    return success;
}

Error_code Queue::retrieve(const Queue_entry &item)
{
    if(count<=0)return underflow;
    item=entry[front];
    return success;
}