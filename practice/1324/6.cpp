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

int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}
V a,dp,ans;
vector<vector<ll> > g;
void dfs(ll src, ll par)
{
    dp[src]=a[src];
    for(auto it : g[src])
    {
        if(it==par)continue;
        dfs(it,src);
        dp[src]+=max((ll)0,dp[it]);
    }
}

void dfs2(ll src , ll par)
{
    ans[src]=dp[src];
    for(auto it:g[src])
    {
        if(it==par)continue;
        dp[src]-=max((ll)0,dp[it]);
        dp[it]+=max((ll)0,dp[src]);
        dfs2(it,src);
        dp[it]-=max((ll)0,dp[src]);
        dp[src]+=max((ll)0,dp[it]);
    }
}

int main()
{
    ll n;
    cin>>n;
    ans=dp=a=vector<ll>(n);
    g=vector<vector<ll> >(n);
    rep(i,0,n)
    {
        cin>>a[i];
        if(a[i]==0)a[i]=-1;
    }
    rep(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0,-1);
    dfs2(0,-1);
    rep(i,0,n)
    cout<<ans[i]<<" ";
}