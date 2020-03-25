#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

int main()
{
    ll n;
    cin>>n;
    ll c[n];
    rep(i,0,n)cin>>c[i];
    vector<string> str(n),rev_str(n);
    rep(i,0,n)
    {
        cin>>str[n];
        rev_str[i]=str[i];
        rev_str[i]=reverse(rev_str[i].begin(),rev_str[i].end());
    }
    ll dp[n][2];
    dp[0][0]=0;dp[0][1]=c[0];
    rep(i,1,n)
    {
        dp[i][0]=dp[i][1]=1e18;
        if(str[i]>=str[i-1])
        dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(str[i]>=rev_str[i-1])
        dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(rev_str[i]>=str[i-1])
        dp[i][1]=min(dp[i][1],dp[i-1][0]);
        if(rev_str[i]>=rev_str[i-1])
        dp[i][1]=min(dp[i][1],dp[i-1][1]);
    }
    ll ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans>(1e15))
    return cout<<"-1",0;
    else 
    return cout<<ans,0;
}