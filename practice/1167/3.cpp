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

vector<vector<ll> >adj;
vector<ll> vis;

void dfs(ll s , vector<ll> & v)
{
    v.pb(s);
    vis[s]=1;
    for(auto it: adj[s])
    {
        if(vis[s]!=1)
        dfs(it,v);
    }
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj=vector<vector<ll> >(n);
        vis=vector<ll>(n,0);
        rep(i,0,m)
        {
            ll sz;
            cin>>sz;
            ll v[sz];
            rep(j,0,sz)
            {cin>>v[j];v[j]--;}
            rep(j,1,sz)
            {
                ll u=v[j];
                ll v=v[j-1];
                adj[u].pb(v);
                adj[v].pb(u);
            }   
        }

        ll val[n];
        rep(i,0,n)
        {
            if(vis[i]==0)
            {
                vector<ll> v;
                dfs(i,v);
                ll ans=v.size();
                rep(j,0,v.size())
                val[v[j]]=ans;
            }
        }
        rep(i,0,n)
        cout<<val[i]<<" ";
    }

}