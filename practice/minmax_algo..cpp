class Board{
    public:
    Board();
    int done() const;
    void play(Move try_it);
    int evaluate() const;
    nit legal_moves(Stack &moves) const;
    int worst_case() const;
    int better(int value,int old_value) const;

    void print();
    void instructions() const;
}

look_ahead (Board obj)
{
    
}