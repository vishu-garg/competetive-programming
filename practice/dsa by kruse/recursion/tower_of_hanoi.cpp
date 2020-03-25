#include<bits/stdc++.h>
using namespace std;
#define ll long long

void move(int count , int start, int finish , int temp)
{
    // if(count>0)
    // {
    //     move(count-1,start,temp,finish);
    //     cout<<"Move disk "<<count<<" from "<<start<<" to "<<finish<<" . "<<endl;
    //     move(count-1,temp,finish,start);
    // }

    while(count>0)
    {
        int swap;
        while(count>0)
        {
            move(count-1,start,temp,finish);
            cout<<"Move "<<count<<" disk from "<<start<<" to "<<finish<<" ." <<endl;
            count--;
            swap=start;
            start=temp;
            temp=swap;
        }
    }
}

int main()
{
    move(5,1,3,2);// move 64 such discs from 1 to 3 and 2 as a temporary storage
    /*
        move(63,1,2,3);
        move(63,2,3,1);
    */
}