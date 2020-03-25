#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll s,w[3],cnt=0;
        cin>>s;
        ll s1=s;
        cin>>w[0]>>w[1]>>w[2];
        if(w[0]+w[1]+w[2]<=s)
        cout<<"1"<<endl;
        else if(w[0]+w[1]<=s || w[2]+w[1]<=s)
        cout<<"2"<<endl;
        else 
        cout<<"3"<<endl;
    }
}