#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll x=1,y=1;
    for(ll i=1;i<=k-1;i++)
    {
        cout<<2<<" ";
        for(ll j=0;j<2;j++)
        {
            cout<<x<<" "<<y<<" ";

            if(x%2==1)
            {
                if(y!=m)y++;
                else x++;
            }
            else
            {
                if(y!=1)y--;
                else x++;
            }
        }
        cout<<endl;
    }
    cout<<(n*m)-(2*(k-1))<<" ";
    for(ll i=1;i<=(n*m)-(2*(k-1));i++)
    {
        cout<<x<<" "<<y<<" ";
        if(x%2==1)
        {
            if(y!=m)y++;
            else x++;
        }
        else
        {
            if(y!=1)y--;
            else x++;
        }
    }
}