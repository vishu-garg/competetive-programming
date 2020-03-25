#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int size;
    cout<<"Board Size = ? "<<endl;
    cin>>size;
    if(size<0)
    cout<<"Number must be positive!";
    else
    {
        Queen(borad_size);
        solve_from(configuration);
    }
    
}