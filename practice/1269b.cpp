#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    for(ll i=0;i<n;i++)
    cin>>b[i];

    ll cnd[n];
    for(ll i=0;i<n;i++)
    {
        if(b[0]>=a[i])
        cnd[i]=b[0]-a[i];
        else 
        cnd[i]=b[0]-a[i]+m;

        // cout<<cnd[i]<<endl;
    }
    sort(cnd,cnd+n);
    sort(b,b+n);
    for(ll i=0;i<n;i++)
    {
        ll fnd=0;
        ll ans[n];
        for(ll j=0;j<n;j++){
            ans[j]=(a[j]+cnd[i])%m;
        }
        sort(ans,ans+n);
        for(ll j=0;j<n;j++)
        {
            if(ans[j]!=b[j])
            {
                fnd=1;
                j=n;
            }
        }
        if(fnd==0){
        cout<<cnd[i];
        i=n;
        }
    }

}
