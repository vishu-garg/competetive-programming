#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;i++)

vector<vector<ll> >fact;
ll find(ll n)
{
    ll dp[n+1];
    if(n==0)
    return 1;
    if(n==1)
    return 1;
    dp[0]=1;
    dp[1]=1;
    rep(i,2,n+1)
    dp[i]=0;
    rep(i,2,n+1)
    {
        rep(j,1,i+1)
        {
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}

int main()
{
   
    ll n;
    cin>>n;
    // cout<<ans(n);
    cout<<find(n);
}


/*
    A BST IS A TREE WHERE PARENT VALUE IS 
    GREATER THAN ALL OF ITS LEFT CHILD 
    SMALLER THAN ALL OF OTS RIGHT CHILD
*/