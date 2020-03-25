#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> v(100001,0);
    ll mx=0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(mx<temp)
        mx=temp;
        v[temp]++;
    }
    ll point[mx+1]={0};
    point[0]=0;
    point[1]=v[1];
    for(ll i=2;i<=mx;i++)
    {
        point[i]=max(point[i-1],point[i-2]+v[i]*i);
    }
    cout<<point[mx];
}