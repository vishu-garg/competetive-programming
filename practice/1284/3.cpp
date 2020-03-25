#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    ll ans=0;
    cin>>n>>m;
    ll f[n+1];
    f[0]=1;
    for(ll i=1;i<=n;i++)
    {
        f[i]=f[i-1]*i%m;
    }
    for(ll i=1;i<=n;i++)
    {
        ll temp=1;
        temp=(temp*f[i])%m;
        temp=((temp%m)*(f[n-i+1]%m))%m;
        temp=((temp%m)*((n-i+1)%m))%m;
        ans=((ans%m)+(temp%m))%m;
    }
    cout<<ans%m;
}