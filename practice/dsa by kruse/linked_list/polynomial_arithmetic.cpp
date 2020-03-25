#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Term {
    int degree;
    double coefficient;
    Term (int exponent =0, double scalar=0);
};
Term::Term(int exponent , double scalar)
{
    degree = exponent;
    coefficent = scalar;
}

class Polynomial
{
private:
    double value;
public:
    Polynomial();
    void read();
    void print();
    void equals_sum(Polynomial p, Polynomial q);
};


Polynomial::Polynomial()
{
    value=0;
}

void Polynomial::equals_sum(Polynomial p, Polynomial q)
{
    value = p.value+q.value;
}



bool do_command(char command,stack<int> &stored_polynomials)
{
    Polynomials p,q,r;
    switch(command){
        case '?':
            p.read();
            if(stored_polynomials.push(p)=="overflow")
            cout<<"Warning: Stack is full "<<endl;
            break;
        case '=':
            if(stored_polynomials.empty())
            cout<<"Stack Empty"<<endl;
            else
            {
                stored_polynomials.top(p);
                p.print();
            }
            break;
        case '+':
            if (stored_polynomials.empty( ))
            cout << "Stack empty" << endl;
            else {
            stored_polynomials.top(p);
            stored_polynomials.pop( );
            if (stored_polynomials.empty( )) {
            cout << "Stack has just one polynomial" << endl;
            stored_polynomials.push(p);
            }
            else {
            stored_polynomials.top(q);
            stored_polynomials.pop( );
            r.equals_sum(q, p);
            if (stored_polynomials.push(r) == overflow)
            cout << "Warning: Stack full, lost polynomial" << endl;
            }
            }
            break;
        case 'q':
            cout<< "Calculation finished." << endl;
            return false;
    }
    return true;
}

int main()
{
    stack<int> stored_polynomials;
    intro();
    instruct();
    while(do_command(get_command(),stored_polynomials));
}
