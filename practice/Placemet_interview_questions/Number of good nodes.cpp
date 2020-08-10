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
const ll N=100005;
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
vector<vector<ll> >adj(N);
int vis[N];
void dfs(ll src,ll prv)
{
    vis[src]=1;
    for(ll i=0;i<adj[src].size();i++)
    {
        if(vis[adj[src][i]]==0)
        {
            dfs(adj[src][i],src);
        }
    }
}

int main()
{
    ll t=1;
//    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        adj=vector<vector<ll> >(n+1);
        rep(i,0,n)
        {
            ll y;
            cin>>y;
            if(i>=1){
            adj[i+1].pb(y);
            adj[y].pb(i+1);}
        }
        ll k=0;
        rep(i,2,n+1)
        {
            if(vis[i]==0)
            {dfs(i,-1);
            k++;}
        }
        ll ans;
        if(vis[1]==1)
        ans=k-1;
        else 
        ans=k;
        cout<<ans<<endl;

    }

}