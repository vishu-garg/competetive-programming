#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll cnt[n]={0};
    cnt[0]=a[0];
    for(ll i=1;i<n;i++)
    cnt[i]=cnt[i-1]+a[i];
    ll s=cnt[n-1];
    if(s%3!=0)
    cout<<"0";
    else
    {
    for(ll i=0;i<n;i++)
    {
    cnt[i]=cnt[n-1]-cnt[i]+a[i];
    if(cnt[i]==s/3)
    cnt[i]=1;
    else
    cnt[i]=0;
    }
    ll sum[n];
    sum[n-1]=cnt[n-1];
    for(ll i=n-2;i>=0;i--)
    sum[i]=sum[i+1]+cnt[i];
    ll s1=0;
    ll ans=0;
    for(ll i=0;i<n-2;i++)
    {
        s1=s1+a[i];
        if(s1==s/3)
        ans=ans+sum[i+2];
    }
    cout<<ans;
    }
}