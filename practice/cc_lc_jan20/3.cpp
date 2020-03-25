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
        ll a[n][m];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll nr=0,cr=0,out=0;
                while(cr+i!=n && i-cr>=0 && out!=1 && cr+j!=m && j-cr>=0 )
                {
                    if(a[i+cr][j]==a[i-cr][j] && a[i][j+cr]==a[i][j-cr])
                    {
                        cr++;
                        nr++;
                    }
                    else{
                    out=1;}
                }
                ans=ans+nr;
            }
        }
        cout<<ans<<endl;
    }
}