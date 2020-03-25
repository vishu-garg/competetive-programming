#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll dp[n+1][n+1][2],a[n+1];
    for(ll i=1;i<n+1;i++)
    cin>>a[i];

    for(ll i=0;i<n+1;i++)
    {
        for(ll j=0;j<n+1;j++)
        dp[i][j][0]=dp[i][j][1]=1e9;
    }
    dp[0][0][1]=0;
    dp[0][0][0]=0;

    for(ll i=1;i<n+1;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(a[i]%2==0)
            {
                dp[i][j+1][0]=min(dp[i-1][j][0],dp[i-1][j][1]+1);
            }
            if(a[i]%2==1 || a[i]==0)
            {
                dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
            }
        }
    }

    cout<<min(dp[n][n/2][0],dp[n][n/2][1]);
}