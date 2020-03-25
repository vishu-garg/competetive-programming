#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n+1]={0};
    for(ll i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;
        a[temp]++;
    }
    ll min=0;
    ll fil[n+1]={0};
    for(ll i=1;i<=n;i++)
    {
        if((max(a[i+1],a[i-1]))==a[i-1])
        fil[i-1]=1;
        else 
        fil[i+1]=1; 
    }
    min=count(fil,fil+n,1);
    ll max=0;
    ll fil2[n+1]={0};
    for(ll i=1;i<=n;i++)
    {
        if(a[i-1]==0)
        fil2[i-1]=1;
        else if(a[i+1]==0)
        fil2[i+1]=1;
        else
        fil2[i]=1;
    }
    max=count(fil2,fil2+n,1);
    cout<<min<<" "<<max;
}