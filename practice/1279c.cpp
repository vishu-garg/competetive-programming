#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll c[n];
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            c[temp]=i;
        }
        ll cur_add=0,ans=0;
        for(ll i=0;i<m;i++)
        {
            ll temp;
            cin>>temp;
            if(c[temp]<=cur_add)
            ans++;
            else
            {
                ans=ans+((c[temp]-i)*2);
                ans+=1;
                cur_add=c[temp];
            }
        }
        cout<<ans<<endl;
    }
}