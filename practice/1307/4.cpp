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
ll n,m,k;
V s;
vector<vector<ll> >g;
V vis;
ll dist_1[200005],dist_n[200005],q[200005];

void bfs(ll* dist_1,ll s)
{
    fill(dist_1,dist_1+n,INF);
    ll qh=0,qt=0;
    q[qh++]=s;
    dist_1[s]=0;
    while(qt<qh)
    {
        ll x=q[qt++];
        for(ll y : g[x]){
            if(dist_1[y]==INF)
            {
                dist_1[y]=dist_1[x]+1;
                q[qh++]=y;
            }
        }
    }
}


int main()
{
    ll t=1;
//    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        s=V(k);
        vis=V(n);
        g=vector<vector<ll> >(n);
        rep(i,0,k)
        {cin>>s[i];s[i]-=1;}
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            x--;y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        V x(k);
        bfs(dist_1,0);
        bfs(dist_n,n-1);
        vector<pair<ll,ll> >data;
        rep(i,0,k)
        {
            data.pb({dist_1[s[i]]-dist_n[s[i]],s[i]});
        }
        sort(data.begin(),data.end());
        ll best=0;
        ll mx=-INF;
        for(auto it : data){
            ll a=it.second;
            best=max(best,mx+dist_n[a]);
            mx=max(mx,dist_1[a]);
        }
        cout<<min(dist_1[n-1],best+1);
    }
}
