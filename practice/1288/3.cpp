#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll mod=1e9+7;
int main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    ll asc[11][n+1],dsc[11][n+1];
    memset(asc,0,sizeof(asc));
    memset(dsc,0,sizeof(dsc));

    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==1)
            {
                asc[i][j]=dsc[i][j]=1;
            }
            else
            {
                for(ll k=j;k>=1;k--)
                {
                    asc[i][j]+=asc[i-1][k];
                    asc[i][j]%=mod;
                }
                for(ll k=j;k<=n;k++)
                {
                    dsc[i][j]+=dsc[i-1][k];
                    dsc[i][j]%=mod;
                }
            }
            
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
            ans+=(asc[m][i]*dsc[m][j]);
            ans%=mod;
        }
    }
    cout<<ans;

}