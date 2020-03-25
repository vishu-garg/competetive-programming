#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll ans=0;
    for(ll i=n-k;i<n;i++)
    ans=ans+a[i];
    ll pnt=n-k+1;
    ll a1[n-k+1]={0};
    a1[n-k]=ans;
    for(ll i=n-k-1;i>=0;i--)
    a1[i]=a1[i+1]-a[i+k]+a[i];

    for(ll i=n-k-1;i>=0;i--)
    {
        ll temp=a1[i];
        if(temp<ans)
        {
            ans=temp;
            pnt=i+1;
        }
    }
    cout<<pnt;
}