class Queue{
    public:
    Queue();
    bool empty() const;
    Error_code append(Queue_entry &item);
    Error_code serve();
    Error_code retrieve(Queue_entry &item);
};

class Extended_queue : public Queue {
    public:
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};