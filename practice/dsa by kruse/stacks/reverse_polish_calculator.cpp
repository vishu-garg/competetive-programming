typedef double Stack_entry;
#include <stack>

char get_command( )
{
char command;
bool waiting = true;
cout << "Select command and press < Enter > :";
while (waiting) {
cin >> command;
command = tolower(command);
if (command == '?' || command == '=' || command == '+' ||
command == '−' || command == '*' || command == '/' ||
command == 'q') waiting = false;
else {
cout << "Please enter a valid command:" << endl
<< "[?]push to stack [=]print top" <<endl
<< "[+] [−] [*] [/] are arithmetic operations" << endl
<< "[Q]uit." << endl;
}
}

bool do_command(char command, Stack &numbers)
{
    double p,q;
    switch (command){
        case '?':
        cout<<"Enter a real number"<<endl;
        cin>>p;
        if(numbers.push(p)==overflow)
        cout<<"Warn: Stack is full"<<endl;
        break;

        case '=':
        if(numbers.top(p)==underflow)
        cout<<"Stack Empty"<<endl;
        else 
        cout<<p<<endl;
        break;

        case '+':
        if(numbers.top(p)==underflow)
        cout<<"Stack empty"<<endl;
        else 
        {
            numbers.pop();
            if(number.top(q)==underflow)
            cout<<"Stack contains only one number";
            else 
            {
                numbers.pop();
                if(numbers.push(p+q)==overflow)
                cout<<"Stack is full";
            }
        }
        break;

        case 'Q':
        cout<<"Finishing Calculation..."<<endl;
        return false;
    }
    return true;
}
return command;
}

int main()
{
    Stack stored_numbers;
    introduction();
    instructions();
    while(do_command(get_commmand(),stored_numbers));
}