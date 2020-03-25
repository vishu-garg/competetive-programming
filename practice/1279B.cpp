#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        ll a[n];
        for(ll i=0;i<n;i++)
        cin>>a[i];
        ll ans=0,sum=0,m=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]>a[m])
            m=i;
            sum=sum+a[i];
            if(sum>s && sum-a[m]<=s)
            ans=m+1;
        }
        cout<<ans<<endl;
    }
}