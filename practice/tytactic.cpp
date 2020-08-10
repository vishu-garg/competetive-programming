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

ll skill[100005],intime[100005],outtime[100005];
vector<ll> sm(200007,0);
ll tme=1;
vector<ll>adj[100005];
ll node[200005];
void dfs(ll src, ll prv)
{
    intime[src]=tme;
    tme++;
    for(ll i=0;i<adj[src].size();i++)
    {
        if(prv!=adj[src][i])
        {
            dfs(adj[src][i],src);
        }
    }
    outtime[src]=tme;
    tme++;
}

void build(ll v, ll l , ll r)
{
    if(l==r)
    {node[v]=sm[v];return;}
    ll mid=(l+r)/2;
    build(2*v,l,mid);
    build(2*v+1,mid+1,r);
    node[v]=node[2*v]+node[2*v+1];
    return;
}

ll query(ll v, ll l ,ll  r, ll st , ll en)
{
    if(l>=st && en>=r)
    return node[v];
    if(l>en || r<st)
    return 0;
    ll ans=0;
    ll mid=(l+r)/2;
    ans=query(2*v,l,mid,st,mid(en,mid))+query(2*v+1,mid+1,en,max(mid+1,st),en);
    return ans;
}

void update(ll v, ll l , ll r, ll pnt, ll val)
{
    if(l==pnt && r==pnt)
    {node[v]=val;return;}
    if(l>pnt || r<pnt)
    return;
    ll mid=(l+r)/2;
    update(2*v,l,mid,pnt,val);
    update(2*v+1,l,mid,pnt,val);
    node[v]=node[2*v]+node[2*v+1];
    return;
}

int main()
{
    ll t=1;
//    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        rep(i,1,n+1)
        cin>>skill[i];
        rep(i,1,n)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);

        // sm=vector<ll>(tme+1,0);

        rep(i,1,n+1)
        {
            sm[intime[i]]=skill[i];
        }

        build(1,1,tme);

        rep(i,0,m)
        {
            char c;
            cin>>c;
            if(c=='Q')
            {
                ll s;
                cin>>s;
                ll ans=query(1,1,tme,intime[s],outtime[s]);
                cout<<ans<<endl;
            }

            else if(c=='U')
            {
                ll s,val;
                update(1,tme,intime[s],val);
            }
        }
    }
}