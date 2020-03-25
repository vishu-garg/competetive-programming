#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x1;
        cin>>x1;
        if(x1<14)
        cout<<"NO";
        else
        {
        x1=x1%14;
        if(x1>=1 && x1<=6)
        cout<<"YES";
        else
        cout<<"NO";
        }
        cout<<endl;
    }
}