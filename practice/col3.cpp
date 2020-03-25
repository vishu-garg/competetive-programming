#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,x;
    cin>>n>>x;
    if(n<x+1)
    cout<<"-1";
    else
    {
        vector<vector<ll> > h(n);
        ll c1=1;
        for(ll i=0;i<n;i++)
        {
            for(ll j=1;j<=x;j++)
            {
                h[i].push_back(c1);
                c1++;
            }
        }
        ll k2=0;
        for(ll i=0;i<n;i++)
        {
            ll cnt=0;
            while(cnt!=x)
            {
            ll k=k2%n;
            if(k!=i && h[k].size()!=(2*x)){
                h[k].push_back(h[i][cnt]);
                cnt++;}
            k2++;
            }
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<(2*x);j++)
            cout<<h[i][j]<<" ";
            cout<<endl;
        }
    }
    
}